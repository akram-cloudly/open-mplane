#include <iostream> 
#include <map>
#include <string>
#include <memory>

#include <HalMplane.h>
#include <MplaneInterfaces.h> 
#include "MplaneProcessingElements.h"
#include "MplaneUplaneConf.h"

extern "C"
{
  void *function_map()
  {
    std::map<std::string, void*> *registered_functions;
    registered_functions = new std::map<std::string, void*>();

    //Halmplane
    (*registered_functions)["int (*halmplane_init)()"] = (void*) halmplane_init;
    (*registered_functions)["int (*halmplane_exit)()"] = (void*) halmplane_exit; 
    
    //MplaneInterface
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update)(interface_t*)"]
     = (void*)halmplane_interface_update;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_description)(const char*, const char*)"]
     = (void*)halmplane_interface_update_description;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_type)(const char*, const char*)"]
     = (void*)halmplane_interface_update_type;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_enabled)(const char*, bool)"]
     = (void*)halmplane_interface_update_enabled;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_l2_mtu)(const char*, int)"]
     = (void*)halmplane_interface_update_l2_mtu;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_vlan_tagging)(const char*, bool)"]
     = (void*)halmplane_interface_update_vlan_tagging;    
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_base_interface)(const char*, const char*)"]
     = (void*)halmplane_interface_update_base_interface;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_vlan_id)(const char*, int)"]
     = (void*)halmplane_interface_update_vlan_id;    
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_mac_address)(const char*, const char*)"]
     = (void*)halmplane_interface_update_mac_address;    
    
    //MplaneProcessingElements
    (*registered_functions)["halmplane_error_t (*halmplane_update_ru_element)(ru_elements_t*)"]
     = (void*)halmplane_update_ru_element;
    
    //MplaneUplaneConf.h
    (*registered_functions)["int (*halmplane_get_tx_array)(const char*, tx_array_t*)"]
     = (void*)halmplane_get_tx_array; 
    (*registered_functions)["const char** (*halmplane_get_tx_array_names)()"]
     = (void*)halmplane_get_tx_array_names; 
    (*registered_functions)["int (*halmplane_get_low_level_tx_endpoint)(const char*, low_level_tx_endpoint_t*)"]
     = (void*)halmplane_get_low_level_tx_endpoint; 
    (*registered_functions)["int (*halmplane_get_low_level_tx_endpoints)(low_level_tx_endpoint_t**, int*)"]
     = (void*)halmplane_get_low_level_tx_endpoints;    

    return registered_functions;
  }
}