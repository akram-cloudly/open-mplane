#include <test_wrapper.h>
#include <wrapper.h>

void test_MplaneInterfaces()
{
    std::cout << "test_MplaneInterface loading..." << std::endl;
    interface_t* interface;
    halmplane_interface_update(interface);
    halmplane_interface_update_description("name", "description");
    halmplane_interface_update_type("name", "type");
    halmplane_interface_update_enabled("name", "enabled");
    halmplane_interface_update_l2_mtu("name", 12);
    halmplane_interface_update_vlan_tagging("name",1);
    halmplane_interface_update_base_interface("name", "baseInterface");
    halmplane_interface_update_mac_address("name", "macAddress");
}

void test_MplaneProcessingElement()
{
    eth_flow_t example_eth_flow = {
    .ru_mac_address = "00:11:22:33:44:55",
    .vlan_id = 100,
    .o_du_mac_address = "66:77:88:99:AA:BB"
    };

    aliasmac_flow_t example_aliasmac_flow = {
    // Initialize fields as necessary
    };

    udpip_flow_t example_udpip_flow = {
    // Initialize fields as necessary
    };

    transport_flow_t example_transport_flow = {
    .interface_name = "eth0",
    .amac_flow = example_aliasmac_flow,
    .e_flow = example_eth_flow,
    .u_flow = example_udpip_flow
    };

    ru_elements_t example_ru_element = {
    .name = "RU1",
    .t_flow = example_transport_flow
    };

    std::cout << std::endl << "test_MplaneProcessingElement is loading..." << std::endl;
    halmplane_update_ru_element(&example_ru_element);
}

void test_MplaneUplaneConf()
{
    std::cout << std::endl << "test_MplaneUplaneConf loading..." << std::endl;

    tx_array_t tx_array;
    rx_array_t rx_arrays;

    low_level_tx_endpoint_t tx_endpoint;
    low_level_tx_endpoint_t* tx_endpoints;

    low_level_rx_endpoint_t rx_endpoint;
    low_level_rx_endpoint_t* rx_endpoints;
    int n_endpoints;
    user_plane_configuration_t uplane_cfg;
    const char *endpoint_name = "endpoint_name";
    e_axcid_t eaxc;
    compression_t compression;
    dynamic_compression_configuration_t config;
    halmplane_carrier_state_cb_t cb;
    // int* n_endpoints

    halmplane_get_tx_array("name", &tx_array);
    halmplane_get_tx_array_names();
    halmplane_get_low_level_tx_endpoint("name", &tx_endpoint);
    halmplane_get_low_level_tx_endpoints(&tx_endpoints, &n_endpoints);
    halmplane_get_rx_array("name", &rx_arrays);
    halmplane_get_rx_array_names();
    halmplane_get_low_level_rx_endpoint("name", &rx_endpoint);
    halmplane_get_low_level_rx_endpoints(&rx_endpoints, &n_endpoints); 
    halmplane_tx_carrier_state_change("name", 0, 1, 2, "new_state", 1);    
    halmplane_rx_carrier_state_change("name", 0, 1, 2, "new_state", 1);
    halmplane_setUPlaneConfiguration(&uplane_cfg);
    halmplane_update_tx_eaxc(endpoint_name, &eaxc);
    halmplane_update_rx_endpoint_compression(endpoint_name, &compression);
    halmplane_update_tx_endpoint_compression(endpoint_name, &compression);
    halmplane_update_rx_endpoint_compression_dyn_config(endpoint_name, &config);
    halmplane_update_tx_endpoint_compression_dyn_config(endpoint_name, &config);
    halmplane_register_rx_carrier_state_cb(cb);
    halmplane_register_tx_carrier_state_cb(cb);
}

void test_MplaneAlarms()
{
    std::cout << "test_MplaneAlarms loading..." << std::endl;
    halmplane_oran_alarm_cb_t callback;
    halmplane_registerOranAlarmCallback(callback);
}

void test_MplaneEcpri()
{
    std::cout << "test_MplaneEcpri loading..." << std::endl;
    halmplane_message5Enabled();

    #if 0
    halmplane_oran_hardware_t hw;
    halmplane_set_ietf_hardware (hw);
    #endif
}

void test_MplaneExternalio()
{
    std::cout << "test_MplaneExternalio loading..." << std::endl;
    external_io_t *io = NULL;
    output_setting_t* out_setting = NULL;
    halmplane_get_io_value(io);
    halmplane_set_io_value(out_setting);
}

void test_MplanePerformanceMgmt()
{
    // std::cout << "test_MplanePerformanceMgmt loading..." << std::endl;
    // epe_measurement_objects_t config;
    // halmplane_epe_meas_cb_t cb;
    // halmplane_oran_perf_meas_cb_t callback;
    // uint8_t interface;
    // double* rssiValue;
    // performance_measurement_params_t* performance_config;
    // transceiver_measurement_objects_t transceiver_config;
    // halmplane_transceiver_meas_cb_t transceiver_cb;
    // rx_window_measurement_objects_t rx_window_config;
    // halmplane_rx_window_meas_cb_t rx_window_cb;
    // tx_measurement_objects_t tx_measurement_config;
    // halmplane_tx_stats_meas_cb_t tx_measurement_cb;
    
    // halmplane_getRssi(interface, rssiValue);
    // // int config, cb;
    // halmplane_activateEpeMeasObjects(config, cb);
    // _get_perf_meas_cb_ptr();
    // halmplane_registerOranPerfMeasCallback(callback);
    // halmplane_configPerfMeasurementParams(performance_config);
    // halmplane_activateTransceiverMeasObjects(transceiver_config, transceiver_cb);
    // halmplane_activateRxWindowMeasObjects(rx_window_config, rx_window_cb);
    // halmplane_activateTxMeasObjects(tx_measurement_config,tx_measurement_cb);
}

//MplaneHardware
void test_MplaneHardwae()
{
    std::cout << "test_MplaneHardwae() ..." << std::endl;
    hw_component_t *hw_comp;
    ietf_hardware_t* hw;
    halmplane_notificationHwStateChange_cb_t cb;
    halmplane_notificationHwStateOper_cb_t Oper_cb;

    halmplane_get_energysaving_state(hw_comp);
    halmplane_get_availability_type(hw_comp);
    halmplane_get_label_content(hw_comp);
    halmplane_get_product_code(hw_comp);
    halmplane_is_energy_saving_enabled(hw_comp);
    halmplane_get_dying_gasp_support(hw_comp);
    halmplane_get_last_service_date(hw_comp);
    halmplane_get_o_ran_name(hw_comp);
    halmplane_get_ietf_hardware(hw);
    halmplane_registerHwStateChange(cb);
    halmplane_registerHwStateOper(Oper_cb);
}

void test_MplaneFan()
{
    // std::cout << std::endl << "Test_MplaneFan()..." << std::endl;
    // fan_state_t* fan_state;
    // halmplane_get_fan_present_and_operating(fan_state);
    // halmplane_get_fan_name(fan_state);
    // halmplane_get_fan_location(fan_state);
    // halmplane_get_fan_vendor_code(fan_state);
    // halmplane_get_fan_speed(fan_state);
    // halmplane_get_fan_target_speed(fan_state);
}

void test_MplaneAntennaCalibration()
{
    antenna_calibration_data_t* antenna_data;
    std::cout <<std::endl << "test_MplaneAntennaCalibration() ..." << std::endl;
    halmplane_start_antenna_calibration(antenna_data);
}

void test_MplaneAld()
{
    std::cout << "test_MplaneAld ...." << std::endl;
    halmplane_ald_communication_output_t* ald_status;
    halmplane_ald_communication_input_s* ald_req;
    uint16_t msg_size;
    
    halmplane_ald_get_counters(ald_status);
    halmplane_ald_get_status(ald_status);
    halmplane_ald_response(ald_req, msg_size);
    halmplane_ald_set_receive_mode(ald_req, msg_size);
    halmplane_ald_request(ald_req, msg_size);
}

void test_MplaneBeamforming()
{
    std::cout << "test_MplaneBeamforming ...." << std::endl;
    char* filepath;
    halmplane_apply_beamforming_file(filepath);
}

void test_MplaneSync()
{
    std::cout << "test_MplaneBeamforming ...." << std::endl;
    ptp_config_t ptp_config;
    ptp_status_t* ptp_status;
    synce_config_t synce_config;
    synce_status_t* synce_status;
    gnss_status_t* gnss_status;

    halmplane_set_ptp_config(ptp_config);
    halmplane_get_ptp_status(ptp_status);
    halmplane_set_synce_config(synce_config);
    halmplane_get_synce_status(synce_status);
    halmplane_get_gnss_status(gnss_status);
}

void test_MplaneDelayMgmt()
{
    std::cout << "test_MplaneDelayMgmt ...." << std::endl;
    o_ru_delay_management_s* ru_delay_mgmt;

    halmplane_setDUToRUDelayMgmnt(ru_delay_mgmt);
}

void test_MplaneModuleCapability()
{
  std::cout << "test_MplaneModuleCapability..." << std::endl;
  module_capability_t* mod_capability;
  halmplane_setDUToRUModuleCapability(mod_capability);
}

void test_MplaneSupervision()
{
    std::cout << "test_MplaneSupervision..." << std::endl;
    halmplane_get_cu_supervison_interval();
    halmplane_set_cu_supervison_interval(0);
}

void test_MplaneTransceiver()
{
    std::cout << "test_MplaneTransceiver..." << std::endl;
    port_transceivers_t* transceivers;
    halmplane_get_port_transceivers(transceivers);
}
