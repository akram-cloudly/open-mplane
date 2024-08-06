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
