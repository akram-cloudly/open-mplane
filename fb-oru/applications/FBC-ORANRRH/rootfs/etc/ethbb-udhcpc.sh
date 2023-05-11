#!/bin/sh -x

printenv >> /var/log/udhcpc.log

# udhcpc script edited by Tim Riker <Tim@Rikers.org>

[ -z "$1" ] && echo "Error: should be called from udhcpc" && exit 1

RESOLV_CONF="/etc/resolv.conf"
[ -n "$subnet" ] && NETMASK="netmask $subnet"

# return 0 if root is mounted on a network filesystem
root_is_nfs() {
        sed -n 's/^[^ ]* \([^ ]*\) \([^ ]*\) .*$/\1 \2/p' /proc/mounts |
        grep -q "^/ \(nfs\|smbfs\|ncp\|coda\)$"
}

have_bin_ip=0
if [ -x /sbin/ip ]; then
  have_bin_ip=1
  BROADCAST="broadcast +"
fi

[ -n "$broadcast" ] && BROADCAST="broadcast $broadcast"

case "$1" in
        deconfig)
                if [ -x /sbin/resolvconf ]; then
                        /sbin/resolvconf -d "${interface}.udhcpc"
                fi
                if ! root_is_nfs ; then
                        if [ $have_bin_ip -eq 1 ]; then
                                /sbin/ip addr flush dev $interface
                                /sbin/ip link set dev $interface up
                        else
                                /sbin/ifconfig $interface 0.0.0.0
                        fi
                fi
                ;;

        renew|bound)
        
        		# save the environment to the log file for this interface
        		printenv >> /var/log/udhcpc-$interface.log
        
                if [ $have_bin_ip -eq 1 ]; then
                        /sbin/ip addr add dev $interface local $ip/$mask $BROADCAST
                else
                        /sbin/ifconfig $interface $ip $BROADCAST $NETMASK
                fi

                if [ -n "$router" ] ; then
                        if ! root_is_nfs ; then
                                if [ $have_bin_ip -eq 1 ]; then
                                        while /sbin/ip route del default dev $interface 2>/dev/null ; do
                                                :                
                                        done                            
                                else                                               
                                        while /sbin/route del default gw 0.0.0.0 dev $interface 2>/dev/null ; do
                                                :                                                       
                                        done                       
                                fi                               
                        fi                                       
                                                                                                                
                        metric=10                              
                        for i in $router ; do                                                           
                                if [ $have_bin_ip -eq 1 ]; then    
                                        /sbin/ip route add default via $i metric $metric
                                else                             
                                        /sbin/route add default gw $i dev $interface metric $metric 2>/dev/null 
                                fi                             
                                metric=$(($metric + 1))                                                 
                        done                                                            
                fi                          
                                                                                                               
                # Update resolver configuration file                                                            
                R=""                                               
                [ -n "$domain" ] && R="domain $domain                                                   
"                                                                                       
                for i in $dns; do           
                        echo "$0: Adding DNS $i"                                                               
                        R="${R}nameserver $i                                                                    
"                                                              
                done                                                                                    
                                                                                        
                if [ -x /sbin/resolvconf ]; then                                   
                        echo -n "$R" | /sbin/resolvconf -a "${interface}.udhcpc"                               
                else                                                                                            
                        echo -n "$R" > "$RESOLV_CONF"          
                fi                                                                                      
                ;;                                                                      
esac                                                                            
                                                                                                               
exit 0