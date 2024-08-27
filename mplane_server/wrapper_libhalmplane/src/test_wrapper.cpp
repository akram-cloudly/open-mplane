#include <test_wrapper.h>
#include <wrapper.h>

void test_MplaneInterfaces()
{
    std::cout << "test_MplaneInterface loading..." << std::endl;
    interface_t* interface;
    _halmplane_interface_update(interface);
    _halmplane_interface_update_description("name", "description");
    _halmplane_interface_update_type("name", "type");
    _halmplane_interface_update_enabled("name", "enabled");
    _halmplane_interface_update_l2_mtu("name", 12);
    _halmplane_interface_update_vlan_tagging("name",1);
    _halmplane_interface_update_base_interface("name", "baseInterface");
    _halmplane_interface_update_mac_address("name", "macAddress");
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
    _halmplane_update_ru_element(&example_ru_element);
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

    _halmplane_get_tx_array("name", &tx_array);
    _halmplane_get_tx_array_names();
    _halmplane_get_low_level_tx_endpoint("name", &tx_endpoint);
    _halmplane_get_low_level_tx_endpoints(&tx_endpoints, &n_endpoints);
    _halmplane_get_rx_array("name", &rx_arrays);
    _halmplane_get_rx_array_names();
    _halmplane_get_low_level_rx_endpoint("name", &rx_endpoint);
    _halmplane_get_low_level_rx_endpoints(&rx_endpoints, &n_endpoints); 
    _halmplane_tx_carrier_state_change("name", 0, 1, 2, "new_state", 1);    
    _halmplane_rx_carrier_state_change("name", 0, 1, 2, "new_state", 1);
    _halmplane_setUPlaneConfiguration(&uplane_cfg);
    _halmplane_update_tx_eaxc(endpoint_name, &eaxc);
    _halmplane_update_rx_endpoint_compression(endpoint_name, &compression);
    _halmplane_update_tx_endpoint_compression(endpoint_name, &compression);
    _halmplane_update_rx_endpoint_compression_dyn_config(endpoint_name, &config);
    _halmplane_update_tx_endpoint_compression_dyn_config(endpoint_name, &config);
    _halmplane_register_rx_carrier_state_cb(cb);
    _halmplane_register_tx_carrier_state_cb(cb);
}

void test_MplaneAlarms()
{
    std::cout << "test_MplaneAlarms loading..." << std::endl;
    halmplane_oran_alarm_cb_t callback;
    _halmplane_registerOranAlarmCallback(callback);
}

void test_MplaneEcpri()
{
    std::cout << "test_MplaneEcpri loading..." << std::endl;
    _halmplane_message5Enabled();
}

void test_MplaneExternalio()
{
    std::cout << "test_MplaneExternalio loading..." << std::endl;
    external_io_t *io = NULL;
    output_setting_t* out_setting = NULL;
    _halmplane_get_io_value(io);
    _halmplane_set_io_value(out_setting);
}

void test_MplanePerformanceMgmt()
{
    std::cout << "test_MplaneProcessingElements loading..." << std::endl;
    epe_measurement_objects_t config;
    halmplane_epe_meas_cb_t cb;
    halmplane_oran_perf_meas_cb_t callback;
    uint8_t interface;
    double* rssiValue;
    performance_measurement_params_t* performance_config;
    transceiver_measurement_objects_t transceiver_config;
    halmplane_transceiver_meas_cb_t transceiver_cb;
    rx_window_measurement_objects_t rx_window_config;
    halmplane_rx_window_meas_cb_t rx_window_cb;
    tx_measurement_objects_t tx_measurement_config;
    halmplane_tx_stats_meas_cb_t tx_measurement_cb;
    
    _halmplane_getRssi(interface, rssiValue);
    // int config, cb;
    _halmplane_activateEpeMeasObjects(config, cb);
    _halmplane_registerOranPerfMeasCallback(callback);
    _halmplane_configPerfMeasurementParams(performance_config);
    _halmplane_activateTransceiverMeasObjects(transceiver_config, transceiver_cb);
    _halmplane_activateRxWindowMeasObjects(rx_window_config, rx_window_cb);
    _halmplane_activateTxMeasObjects(tx_measurement_config,tx_measurement_cb);
}

//MplaneHardware
void test_MplaneHardwae()
{
    std::cout << "test_MplaneHardwae() ..." << std::endl;
    hw_component_t *hw_comp;
    ietf_hardware_t* hw;
    halmplane_notificationHwStateChange_cb_t cb;
    halmplane_notificationHwStateOper_cb_t Oper_cb;

    _halmplane_get_energysaving_state(hw_comp);
    _halmplane_get_availability_type(hw_comp);
    _halmplane_get_label_content(hw_comp);
    _halmplane_get_product_code(hw_comp);
    _halmplane_is_energy_saving_enabled(hw_comp);
    _halmplane_get_dying_gasp_support(hw_comp);
    _halmplane_get_last_service_date(hw_comp);
    _halmplane_get_o_ran_name(hw_comp);
    _halmplane_get_ietf_hardware(hw);
    _halmplane_registerHwStateChange(cb);
    _halmplane_registerHwStateOper(Oper_cb);
}

void test_MplaneFan()
{
    std::cout << std::endl << "Test_MplaneFan()..." << std::endl;
    fan_state_t* fan_state;
    _halmplane_get_fan_present_and_operating(fan_state);
    _halmplane_get_fan_name(fan_state);
    _halmplane_get_fan_location(fan_state);
    _halmplane_get_fan_vendor_code(fan_state);
    _halmplane_get_fan_speed(fan_state);
    _halmplane_get_fan_target_speed(fan_state);
}

void test_MplaneAntennaCalibration()
{
    antenna_calibration_data_t* antenna_data;
    std::cout <<std::endl << "test_MplaneAntennaCalibration() ..." << std::endl;
    _halmplane_start_antenna_calibration(antenna_data);
}

void test_MplaneAld()
{
    std::cout << "test_MplaneAld ...." << std::endl;
    const halmplane_ald_communication_output_t* ald_status;
    halmplane_ald_communication_input_s* ald_req;
    uint16_t msg_size;
    
    _halmplane_ald_get_counters(ald_status);
    _halmplane_ald_get_status(ald_status);
    _halmplane_ald_response(ald_req, msg_size);
    _halmplane_ald_set_receive_mode(ald_req, msg_size);
}

void test_MplaneBeamforming()
{
    std::cout << "test_MplaneBeamforming ...." << std::endl;
    char* filepath;
    _halmplane_apply_beamforming_file(filepath);
}

void test_MplaneSync()
{
    std::cout << "test_MplaneBeamforming ...." << std::endl;
    ptp_config_t ptp_config;
    ptp_status_t* ptp_status;
    synce_config_t synce_config;
    synce_status_t* synce_status;
    gnss_status_t* gnss_status;

    _halmplane_set_ptp_config(ptp_config);
    _halmplane_get_ptp_status(ptp_status);
    _halmplane_set_synce_config(synce_config);
    _halmplane_get_synce_status(synce_status);
    _halmplane_get_gnss_status(gnss_status);
}

void test_MplaneDelayMgmt()
{
    std::cout << "test_MplaneDelayMgmt ...." << std::endl;
    o_ru_delay_management_s* ru_delay_mgmt;

    _halmplane_setDUToRUDelayMgmnt(ru_delay_mgmt);
}
