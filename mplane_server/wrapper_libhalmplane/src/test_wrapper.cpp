#include <test_wrapper.h>
#include <wrapper.h>

void test_MplaneInterfaces()
{
    std::cout << "test_MplaneInterface loading..." << std::endl;
    halmplane_interface_update_description_("name", "description");
    halmplane_interface_update_type_("name", "type");
    halmplane_interface_update_enabled_("name", "enabled");
    halmplane_interface_update_l2_mtu_("name", 12);
    halmplane_interface_update_vlan_tagging_("name",1);
    halmplane_interface_update_base_interface_("name", "baseInterface");
    halmplane_interface_update_mac_address_("name", "macAddress");
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
    halmplane_update_ru_element_(&example_ru_element);
}

void test_MplaneUplaneConf()
{
    std::cout << std::endl << "test_MplaneUplaneConf loading..." << std::endl;

    tx_array_t tx_array;
    low_level_tx_endpoint_t tx_endpoint;
    low_level_tx_endpoint_t* tx_endpoints;
    int n_endpoints;

    halmplane_get_tx_array_("name", &tx_array);
    halmplane_get_tx_array_names_();
    halmplane_get_low_level_tx_endpoint_("name", &tx_endpoint);
    halmplane_get_low_level_tx_endpoints(&tx_endpoints, &n_endpoints);
}
