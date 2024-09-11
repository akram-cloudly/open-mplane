/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "MplaneInterfaces.h"
#include <iostream>

halmplane_error_t
halmplane_interface_update(interface_t* interface) {
  std::cout << "halmplane_interface_update() loading..." << std::endl;
  return NONE;
}

halmplane_error_t
halmplane_interface_update_description(
    const char* name, const char* description) {
  std::cout << "halmplane_interface_update_description() loading..." << std::endl;

  return NONE;
}

halmplane_error_t
halmplane_interface_update_type(const char* name, const char* type) {
  
  std::cout << "halmplane_interface_update_type() loading..." << std::endl;

  return NONE;
}

halmplane_error_t
halmplane_interface_update_enabled(const char* name, bool enabled) {
  std::cout << "halmplane_interface_update_enabled() loading..." << std::endl;
  return NONE;
}

halmplane_error_t
halmplane_interface_update_l2_mtu(const char* name, int l2Mtu) {
  std::cout << "halmplane_interface_update_l2_mtu() loading..." << std::endl;
  return NONE;
}

halmplane_error_t
halmplane_interface_update_vlan_tagging(const char* name, bool vlanTagging) {
  std::cout << "halmplane_interface_update_vlan_tagging() loading..." << std::endl;
  return NONE;
}

halmplane_error_t
halmplane_interface_update_base_interface(
    const char* name, const char* baseInterface) {
  std::cout << "halmplane_interface_update_base_interface() loading..." << std::endl;

  return NONE;
}

halmplane_error_t
halmplane_interface_update_vlan_id(const char* name, int vlanId) {
  std::cout << "halmplane_interface_update_vlan_id() loading..." << std::endl;
  return NONE;
}

halmplane_error_t
halmplane_interface_update_mac_address(
    const char* name, const char* macAddress) {
  std::cout << "halmplane_interface_update_mac_address() loading..." << std::endl;
  return NONE;
}
