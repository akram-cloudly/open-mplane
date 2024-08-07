#ifndef WRAPPER_H_
#define WRAPPER_H_

#include <iostream>
#include <memory>
 
#include "MplaneInterfaces.h"
#include "MplaneProcessingElements.h"
#include "MplaneUplaneConf.h"
#include "HalMplane.h"
#include "MplaneAlarms.h"
// 

class Wrapper
{
  public:
  ~Wrapper()
  {
    std::cout << "Wrapper destructor is running" << std::endl;
  }

};

extern "C"
{
  void* function_map();
};

int wrapper_halmplane_init();
void wrapper_halmplane_exit();

// //HalMplane
int _halmplane_init();
int _halmplane_exit();


// //MplaneInterfaces
halmplane_error_t _halmplane_interface_update(interface_t* interface)__attribute__((weak));
halmplane_error_t _halmplane_interface_update_description(
  const char* name, const char* description);
halmplane_error_t _halmplane_interface_update_type(
  const char* name, const char* type);
halmplane_error_t _halmplane_interface_update_enabled(
  const char* name, bool enabled);
halmplane_error_t _halmplane_interface_update_l2_mtu(
  const char* name, int l2Mtu);
halmplane_error_t _halmplane_interface_update_vlan_tagging(
  const char* name, bool vlanTagging);
halmplane_error_t _halmplane_interface_update_base_interface(
  const char* name, const char* baseInterface);
halmplane_error_t _halmplane_interface_update_vlan_id(
  const char* name, int vlanId);
halmplane_error_t _halmplane_interface_update_mac_address(
      const char* name, const char* macAddress);

// //MplaneProcessingElement module api
halmplane_error_t _halmplane_update_ru_element(ru_elements_t* ru_element);

// //MplaneUplaneConf
int _halmplane_get_tx_array(const char* name, tx_array_t* tx_array);
const char** _halmplane_get_tx_array_names();
int _halmplane_get_low_level_tx_endpoint(const char* name, low_level_tx_endpoint_t* tx_endpoint);
int _halmplane_get_low_level_tx_endpoints(low_level_tx_endpoint_t** tx_endpoints, int* n_endpoints);
int _halmplane_get_rx_array(const char* name, rx_array_t* rx_arrays);
const char** _halmplane_get_rx_array_names();
int _halmplane_get_low_level_rx_endpoint(
    const char* name, low_level_rx_endpoint_t* rx_endpoint);
int _halmplane_get_low_level_rx_endpoints(
    low_level_rx_endpoint_t** rx_endpoints, int* n_endpoints);
int _halmplane_tx_carrier_state_change(
    const char* name,
    uint64_t chbw,
    uint64_t center,
    double gain,
    const char* new_state,
    int do_apply);

int _halmplane_rx_carrier_state_change(
    const char* name,
    uint64_t chbw,
    uint64_t center,
    double gain_correction,
    const char* new_state,
    int do_apply);

int _halmplane_setUPlaneConfiguration(user_plane_configuration_t* uplane_cfg);
int _halmplane_update_tx_eaxc(const char* endpoint_name, e_axcid_t* eaxc);
int _halmplane_update_rx_eaxc(const char* endpoint_name, e_axcid_t* eaxc);
int _halmplane_update_rx_endpoint_compression(
    const char* endpoint_name, compression_t* compression);
int _halmplane_update_tx_endpoint_compression(
    const char* endpoint_name, compression_t* compression);
int _halmplane_update_rx_endpoint_compression_dyn_config(
    const char* endpoint_name, dynamic_compression_configuration_t* config);
int _halmplane_update_tx_endpoint_compression_dyn_config(
    const char* endpoint_name, dynamic_compression_configuration_t* config);
int _halmplane_register_rx_carrier_state_cb(halmplane_carrier_state_cb_t cb);

int _halmplane_register_tx_carrier_state_cb(halmplane_carrier_state_cb_t cb);

// MplaneAlarms
int _halmplane_registerOranAlarmCallback(halmplane_oran_alarm_cb_t callback);


#define capture_source_as_str(src, strname) src; const static char* strname = #src;

#endif /* WRAPPER_H_ */
