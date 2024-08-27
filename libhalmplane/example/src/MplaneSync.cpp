#include "MplaneSync.h"
#include <iostream>

halmplane_error_t halmplane_set_ptp_config(const ptp_config_t ptp_config)
{
    std::cout << "halmplane_set_ptp_config() loading..." << std::endl; 
    return  NONE;
}

halmplane_error_t halmplane_get_ptp_status(ptp_status_t* ptp_status)
{
    std::cout << "halmplane_get_ptp_status() loading..." << std::endl; 
    return  NONE;   
}

halmplane_error_t halmplane_set_synce_config(const synce_config_t synce_config)
{
    std::cout << "halmplane_set_synce_config() loading..." << std::endl; 
    return  NONE;  
}

halmplane_error_t halmplane_get_synce_status(synce_status_t* synce_status)
{
    std::cout << "halmplane_get_synce_status() loading..." << std::endl; 
    return  NONE; 
}

halmplane_error_t halmplane_set_gnss_config(const gnss_config_t gnss_config)
{
    std::cout << "halmplane_set_gnss_config() loading..." << std::endl; 
    return  NONE; 
}

halmplane_error_t halmplane_get_gnss_status(gnss_status_t* gnss_status)
{
    std::cout << "halmplane_get_gnss_status() loading..." << std::endl; 
    return  NONE;      
}