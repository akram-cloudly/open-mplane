#ifndef TEST_WRAPPER_H_
#define TEST_WRAPPER_H_

#include "MplaneInterfaces.h"
// #include "MplaneProcessingElements.h"

// sample ru_elements for to test test_MplaneProcessingElement apis

// eth_flow_t example_eth_flow = {
//     .ru_mac_address = "00:11:22:33:44:55",
//     .vlan_id = 100,
//     .o_du_mac_address = "66:77:88:99:AA:BB"
// };

// aliasmac_flow_t example_aliasmac_flow = {
//     // Initialize fields as necessary
// };
// udpip_flow_t example_udpip_flow = {
//     // Initialize fields as necessary
// };
// transport_flow_t example_transport_flow = {
//     .interface_name = "eth0",
//     .amac_flow = example_aliasmac_flow,
//     .e_flow = example_eth_flow,
//     .u_flow = example_udpip_flow
// };
// ru_elements_t example_ru_element = {
//     .name = "RU1",
//     .t_flow = example_transport_flow
// };

void test_MplaneInterfaces();
void test_MplaneProcessingElement();
void test_MplaneUplaneConf();
void test_MplaneAlarms();
void test_MplaneEcpri();
void test_MplaneExternalio();
void test_MplanePerformanceMgmt();
void test_MplaneHardwae();
void test_MplaneFan();
void test_MplaneAntennaCalibration();
void test_MplaneAld();
void test_MplaneBeamforming();
void test_MplaneSync();
void test_MplaneDelayMgmt();
void test_MplaneModuleCapability();
void test_MplaneSupervision();

#endif /* TEST_WRAPPER_H_ */