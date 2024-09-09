#include <iostream> 
#include <map>
#include <string>
#include <memory>

#include <HalMplane.h>
#include <MplaneInterfaces.h> 
#include "MplaneProcessingElements.h"
#include "MplaneUplaneConf.h"
#include "MplaneAlarms.h"
#include "MplaneEcpri.h"
#include "MplaneExternalio.h"
#include "MplanePerformanceMgmt.h"
#include "MplaneHardware.h"
#include "MplaneFan.h"
#include "MplaneAntennaCalibration.h"
#include "MplaneAld.h"
#include "MplaneBeamforming.h"
#include "MplaneSync.h"
#include "MplaneDelayMgmt.h"
#include "MplaneSupervision.h"


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
    (*registered_functions)["int (*halmplane_get_rx_array)(const char*, rx_array_t*)"]
     = (void*)halmplane_get_rx_array;
    (*registered_functions)["const char** (*halmplane_get_rx_array_names)()"]
     = (void*)halmplane_get_rx_array_names;  
    (*registered_functions)["int (*halmplane_get_low_level_rx_endpoint)(const char*, low_level_rx_endpoint_t*)"]
     = (void*)halmplane_get_low_level_rx_endpoint; 
    (*registered_functions)["int (*halmplane_get_low_level_rx_endpoints)"
    "(low_level_rx_endpoint_t**, int*)"]
     = (void*)halmplane_get_low_level_rx_endpoints;
    (*registered_functions)["int (*halmplane_tx_carrier_state_change)"
    "(const char*, uint64_t, uint64_t, double, const char*, int)"]
     = (void*)halmplane_tx_carrier_state_change;
    (*registered_functions)["int (*halmplane_rx_carrier_state_change)"
    "(const char*, uint64_t, uint64_t, double, const char*, int)"]
     = (void*)halmplane_rx_carrier_state_change;
    (*registered_functions)["int (*halmplane_setUPlaneConfiguration)"
    "(user_plane_configuration_t*)"]
     = (void*)halmplane_setUPlaneConfiguration; 
    (*registered_functions)["int (*halmplane_update_tx_eaxc)"
    "(const char*, e_axcid_t*)"]
     = (void*)halmplane_update_tx_eaxc;
    (*registered_functions)["int (*halmplane_update_rx_eaxc)"
    "(const char*, e_axcid_t*)"]
     = (void*)halmplane_update_rx_eaxc; 
    (*registered_functions)["int (*halmplane_update_rx_endpoint_compression)"
    "(const char*, compression_t*)"]
     = (void*)halmplane_update_rx_endpoint_compression;  
    (*registered_functions)["int (*halmplane_update_tx_endpoint_compression)"
    "(const char*, compression_t*)"]
     = (void*)halmplane_update_tx_endpoint_compression;  
    (*registered_functions)["int (*halmplane_update_rx_endpoint_compression_dyn_config)"
    "(const char*, dynamic_compression_configuration_t*)"]
     = (void*)halmplane_update_rx_endpoint_compression_dyn_config; 
    (*registered_functions)["int (*halmplane_update_tx_endpoint_compression_dyn_config)"
    "(const char*, dynamic_compression_configuration_t*)"]
     = (void*)halmplane_update_tx_endpoint_compression_dyn_config;
    (*registered_functions)["int (*halmplane_register_rx_carrier_state_cb)"
    "(halmplane_carrier_state_cb_t)"]
     = (void*)halmplane_register_rx_carrier_state_cb; 
    (*registered_functions)["int (*halmplane_register_tx_carrier_state_cb)"
    "(halmplane_carrier_state_cb_t)"]
     = (void*)halmplane_register_tx_carrier_state_cb;
    
    //MplaneAlarms
    (*registered_functions)["int (*halmplane_registerOranAlarmCallback)"
    "(halmplane_oran_alarm_cb_t)"]
     = (void*)halmplane_registerOranAlarmCallback;

    //MplaneEcpri
    (*registered_functions)["bool (*halmplane_message5Enabled)(void)"]
     = (void*)halmplane_message5Enabled;
    #if 0     
     (*registered_functions)["bool (*halmplane_set_ietf_hardware)(halmplane_oran_hardware_t)"]
     = (void*)halmplane_set_ietf_hardware;
    #endif

    // //MplaneExternalio
    (*registered_functions)["halmplane_error_t (*halmplane_get_io_value)"
    "(external_io_t*)"]
     = (void*)halmplane_get_io_value;
    (*registered_functions)["halmplane_error_t (*halmplane_set_io_value)"
    "(output_setting_t*)"]
     = (void*)halmplane_set_io_value;

    
    // (*registered_functions)["halmplane_error_t (*halmplane_update_ru_element)"
    // "(ru_elements_t*)"]
    //  = (void*)halmplane_update_ru_element;

    //MplanePerformanceMgmt
    (*registered_functions)["int (*halmplane_activateEpeMeasObjects)"
    "(epe_measurement_objects_t, halmplane_epe_meas_cb_t)"]
     = (void*)halmplane_activateEpeMeasObjects;
    (*registered_functions)["int (*halmplane_registerOranPerfMeasCallback)"
    "(halmplane_oran_perf_meas_cb_t)"]
     = (void*)halmplane_registerOranPerfMeasCallback;
    (*registered_functions)["const halmplane_oran_perf_meas_cb_t (*get_perf_meas_cb_ptr)(void)"]
     = (void*)get_perf_meas_cb_ptr;

    (*registered_functions)["int (*halmplane_getRssi)"
    "(uint8_t, double*)"]
     = (void*)halmplane_getRssi;    
    
    (*registered_functions)["int (*halmplane_configPerfMeasurementParams)"
    "(performance_measurement_params_t*)"]
     = (void*)halmplane_configPerfMeasurementParams;
    (*registered_functions)["int (*halmplane_activateTransceiverMeasObjects)"
    "(transceiver_measurement_objects_t, halmplane_transceiver_meas_cb_t)"]
     = (void*)halmplane_activateTransceiverMeasObjects;
    (*registered_functions)["int (*halmplane_activateRxWindowMeasObjects)"
    "(rx_window_measurement_objects_t, halmplane_rx_window_meas_cb_t)"]
     = (void*)halmplane_activateRxWindowMeasObjects;
    (*registered_functions)["int (*halmplane_activateTxMeasObjects)"
    "(tx_measurement_objects_t, halmplane_tx_stats_meas_cb_t)"]
     = (void*)halmplane_activateTxMeasObjects;
    
    //MplaneHardware
    (*registered_functions)["halmplane_error_t (*halmplane_get_energysaving_state)"
    "(hw_component_t*)"]
     = (void*)halmplane_get_energysaving_state;
    (*registered_functions)["halmplane_error_t (*halmplane_get_availability_type)"
    "(hw_component_t*)"]
     = (void*)halmplane_get_availability_type;
    (*registered_functions)["halmplane_error_t (*halmplane_get_label_content)"
    "(hw_component_t*)"]
     = (void*)halmplane_get_label_content;
    (*registered_functions)["halmplane_error_t (*halmplane_get_product_code)"
    "(hw_component_t*)"]
     = (void*)halmplane_get_product_code;
    (*registered_functions)["halmplane_error_t (*halmplane_is_energy_saving_enabled)"
    "(hw_component_t*)"]
     = (void*)halmplane_is_energy_saving_enabled;
    (*registered_functions)["halmplane_error_t (*halmplane_get_dying_gasp_support)"
    "(hw_component_t*)"]
     = (void*)halmplane_get_dying_gasp_support;
    (*registered_functions)["halmplane_error_t (*halmplane_get_last_service_date)"
    "(hw_component_t*)"]
     = (void*)halmplane_get_last_service_date;
    (*registered_functions)["halmplane_error_t (*halmplane_get_o_ran_name)"
    "(hw_component_t*)"]
     = (void*)halmplane_get_o_ran_name;
    (*registered_functions)["bool (*halmplane_get_ietf_hardware)(ietf_hardware_t*)"]
     = (void*)halmplane_get_ietf_hardware;
    (*registered_functions)["int (*halmplane_registerHwStateChange)"
    "(halmplane_notificationHwStateChange_cb_t)"]
     = (void*)halmplane_registerHwStateChange;
    (*registered_functions)["int (*halmplane_registerHwStateOper)"
    "(halmplane_notificationHwStateOper_cb_t)"]
     = (void*)halmplane_registerHwStateOper;

    //MplaneFan
    (*registered_functions)["halmplane_error_t (*halmplane_get_fan_present_and_operating)"
    "(fan_state_t*)"]
     = (void*)halmplane_get_fan_present_and_operating;
    (*registered_functions)["halmplane_error_t (*halmplane_get_fan_name)"
    "(fan_state_t*)"]
     = (void*)halmplane_get_fan_name;
    (*registered_functions)["halmplane_error_t (*halmplane_get_fan_location)"
    "(fan_state_t*)"]
     = (void*)halmplane_get_fan_location;
    (*registered_functions)["halmplane_error_t (*halmplane_get_fan_vendor_code)"
    "(fan_state_t*)"]
     = (void*)halmplane_get_fan_vendor_code;
    (*registered_functions)["halmplane_error_t (*halmplane_get_fan_speed)"
    "(fan_state_t*)"]
     = (void*)halmplane_get_fan_speed;
    (*registered_functions)["halmplane_error_t (*halmplane_get_fan_target_speed)"
    "(fan_state_t*)"]
     = (void*)halmplane_get_fan_target_speed;
    
    //MplaneAntennaCalibration
    (*registered_functions)["halmplane_error_t (*halmplane_start_antenna_calibration)"
    "(const antenna_calibration_data_t*)"]
     = (void*)halmplane_start_antenna_calibration;
    
    //MplaneAld
    (*registered_functions)["halmplane_error_t (*halmplane_ald_get_counters)"
    "(const halmplane_ald_communication_output_t*)"]
     = (void*)halmplane_ald_get_counters;
    (*registered_functions)["halmplane_error_t (*halmplane_ald_get_status)"
    "(const halmplane_ald_communication_output_t*)"]
     = (void*)halmplane_ald_get_status; 
    (*registered_functions)["halmplane_error_t (*halmplane_ald_response)"
    "(halmplane_ald_communication_input_s*, uint16_t)"]
     = (void*)halmplane_ald_response;  
    (*registered_functions)["halmplane_error_t (*halmplane_ald_set_receive_mode)"
    "(halmplane_ald_communication_input_s*, uint16_t)"]
     = (void*)halmplane_ald_set_receive_mode;
    (*registered_functions)["halmplane_error_t (*halmplane_ald_request)"
    "(halmplane_ald_communication_input_t*, uint16_t)"]
     = (void*)halmplane_ald_request;  

     //MplaneBeamforming    
    (*registered_functions)["halmplane_error_t (*halmplane_apply_beamforming_file)"
    "(char*)"]= (void*)halmplane_apply_beamforming_file;

    //MplaneSync
    (*registered_functions)["halmplane_error_t (*halmplane_set_ptp_config)"
    "(const ptp_config_t)"]= (void*)halmplane_set_ptp_config;
    (*registered_functions)["halmplane_error_t (*halmplane_get_ptp_status)"
    "(ptp_status_t*)"]= (void*)halmplane_get_ptp_status;
    (*registered_functions)["halmplane_error_t (*halmplane_set_synce_config)"
    "(const synce_config_t)"]= (void*)halmplane_set_synce_config;
    (*registered_functions)["halmplane_error_t (*halmplane_get_synce_status)"
    "(synce_status_t*)"]= (void*)halmplane_get_synce_status;
    (*registered_functions)["halmplane_error_t (*halmplane_set_gnss_config)"
    "(const gnss_config_t)"]= (void*)halmplane_set_gnss_config;
    (*registered_functions)["halmplane_error_t (*halmplane_get_gnss_status)"
    "(gnss_status_t*)"]= (void*)halmplane_get_gnss_status; 

    //MplaneDelayMgmt
    (*registered_functions)["int (*halmplane_setDUToRUDelayMgmnt)"
    "(o_ru_delay_management_s*)"]= (void*)halmplane_setDUToRUDelayMgmnt; 
       
    //MplaneModuleCapability
    (*registered_functions)["int (*halmplane_setDUToRUModuleCapability)"
    "(module_capability_t*)"]= (void*)halmplane_setDUToRUModuleCapability; 

    //MplaneSupervision
    (*registered_functions)["uint32_t (*halmplane_get_cu_supervison_interval)(void)"]
    = (void*)halmplane_get_cu_supervison_interval; 
    (*registered_functions)["uint32_t (*halmplane_set_cu_supervison_interval)(uint32_t)"]
    = (void*)halmplane_set_cu_supervison_interval; 

    return registered_functions;
  }
}