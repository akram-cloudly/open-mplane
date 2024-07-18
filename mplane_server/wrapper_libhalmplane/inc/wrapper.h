#ifndef WRAPPER_H_
#define WRAPPER_H_

#include <iostream>
#include <memory>
 
#include "MplaneInterfaces.h"
#include "MplaneProcessingElements.h"
#include "MplaneUplaneConf.h"
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

//HalMplane
int halmplane_init();
int halmplane_exit();


//MplaneInterfaces
halmplane_error_t halmplane_interface_update_(interface_t* interface);
halmplane_error_t halmplane_interface_update_description_(
  const char* name, const char* description);
halmplane_error_t halmplane_interface_update_type_(
  const char* name, const char* type);
halmplane_error_t halmplane_interface_update_enabled_(
  const char* name, bool enabled);
halmplane_error_t halmplane_interface_update_l2_mtu_(
  const char* name, int l2Mtu);
halmplane_error_t halmplane_interface_update_vlan_tagging_(
  const char* name, bool vlanTagging);
halmplane_error_t halmplane_interface_update_base_interface_(
  const char* name, const char* baseInterface);
halmplane_error_t halmplane_interface_update_vlan_id_(
  const char* name, int vlanId);
halmplane_error_t halmplane_interface_update_mac_address_(
      const char* name, const char* macAddress);

//MplaneProcessingElement module api
halmplane_error_t halmplane_update_ru_element_(ru_elements_t* ru_element);

//MplaneUplaneConf
int halmplane_get_tx_array_(const char* name, tx_array_t* tx_array);
const char** halmplane_get_tx_array_names_();
int halmplane_get_low_level_tx_endpoint_(const char* name, low_level_tx_endpoint_t* tx_endpoint);
int halmplane_get_low_level_tx_endpoints(low_level_tx_endpoint_t** tx_endpoints, int* n_endpoints);

#define capture_source_as_str(src, strname) src; const static char* strname = #src;

#endif /* WRAPPER_H_ */
