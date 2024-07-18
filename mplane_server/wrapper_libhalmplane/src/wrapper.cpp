#include <wrapper.h>
#include <hal_loader.h>

const char* configured_libname = NULL;
Hal_Loader* hal_loader = NULL;

int wrapper_halmplane_init()
{
    // std::cout << "wrapper_halmplane_init loading...." << std::endl;
    if(configured_libname == NULL)
    {
      configured_libname = "/usr/lib/libhalmplane.so.0.1.0";
      hal_loader = new Hal_Loader(configured_libname);

      // std::cout << "wrapper_halmplane_init loaded successfully" << std::endl;
    }  
    return 0;
}

int halmplane_init()
{
  capture_source_as_str(int (*halmplane_init)(), ftag);
  // std::cout << "halmplane_init() of wrapper" << std::endl;
  halmplane_init = (int (*)()) hal_loader->get_function("int (*halmplane_init)()");
  if(halmplane_init)
  {
    // std::cout << "halmplane pointer exi" << std::endl;
    int result = halmplane_init();
    return result;
  }

  return 0;
}

int halmplane_exit()
{
  capture_source_as_str(int (*halmplane_exit)(), ftag);
  halmplane_exit = (int (*)()) hal_loader->get_function(ftag);
  if(halmplane_exit)
  {
    return halmplane_exit();
  }

  return 0;
}

halmplane_error_t halmplane_interface_update_(interface_t* interface)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update)(interface_t*), ftag);
  halmplane_interface_update = (halmplane_error_t (*)(interface_t*)) hal_loader->get_function(ftag);
  if(halmplane_interface_update)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update(interface);
  }
  else 
  {
    std::cout << "halmplane_interface update does not exist" << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_description_(
      const char* name, const char* description)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_description)(const char*, const char*), ftag);

  halmplane_interface_update_description = (halmplane_error_t (*)(const char*, const char*)) hal_loader->get_function(ftag);  
  
  if(halmplane_interface_update_description)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_description(name, description);
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_type_(
      const char* name, const char* type)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_type)(const char*, const char*), ftag);

  halmplane_interface_update_type = (halmplane_error_t (*)(const char*, const char*)) hal_loader->get_function(ftag);  
  
  if(halmplane_interface_update_type)
  {
    std::cout << "wrapper  " ;
    return halmplane_interface_update_type(name, type);
  }
  else 
  {
    std::cout <<"function does not exist" << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_enabled_(
  const char* name, bool enabled)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_enabled)(const char*, bool), ftag);
  // halmplane_error_t halmplane_update_ru_element_(ru_elements_t* ru_element);

  halmplane_interface_update_enabled = (halmplane_error_t (*)(const char*, bool)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_enabled)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_enabled(name, enabled);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;

}

halmplane_error_t halmplane_interface_update_l2_mtu_(
  const char* name, int l2Mtu)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_l2_mtu)(const char*, int), ftag);
  
  halmplane_interface_update_l2_mtu = (halmplane_error_t (*)(const char*, int)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_l2_mtu)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_l2_mtu(name, l2Mtu);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_vlan_tagging_(
  const char* name, bool vlanTagging)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_vlan_tagging)(const char*, bool), ftag);
  
  halmplane_interface_update_vlan_tagging = (halmplane_error_t (*)(const char*, bool)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_vlan_tagging)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_vlan_tagging(name, vlanTagging);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_base_interface_(
  const char* name, const char* baseInterface)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_base_interface)(const char*, const char*), ftag);
  
  halmplane_interface_update_base_interface = (halmplane_error_t (*)(const char*, const char*l)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_base_interface)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_base_interface(name, baseInterface);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_vlan_id_(
  const char* name, int vlanId)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_vlan_id)(const char*, int), ftag);
  
  halmplane_interface_update_vlan_id = (halmplane_error_t (*)(const char*, int)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_vlan_id)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_vlan_id(name, vlanId);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_mac_address_(
  const char* name, const char* macAddress)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_mac_address)(const char*, const char*), ftag);
  
  halmplane_interface_update_mac_address = (halmplane_error_t (*)(const char*, const char*)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_mac_address)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_mac_address(name, macAddress);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

//MplaneProcessingElements module api
halmplane_error_t halmplane_update_ru_element_(ru_elements_t* ru_element)
{
  capture_source_as_str(halmplane_error_t (*halmplane_update_ru_element)(ru_elements_t*), ftag);
  
  halmplane_update_ru_element = (halmplane_error_t (*)(ru_elements_t*)) hal_loader->get_function(ftag);

  if(halmplane_update_ru_element)
  {
    std::cout << "wrapper " ;
    return halmplane_update_ru_element(ru_element);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

// MplaneUplaneConf 
int halmplane_get_tx_array_(const char* name, tx_array_t* tx_array)
{
  capture_source_as_str(int (*halmplane_get_tx_array)(const char*, tx_array_t*), ftag);
  
  halmplane_get_tx_array = (int (*)(const char*, tx_array_t*)) hal_loader->get_function(ftag);

  if(halmplane_get_tx_array)
  {
    std::cout << "wrapper " ;
    return halmplane_get_tx_array(name, tx_array);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

const char** halmplane_get_tx_array_names_()
{
  capture_source_as_str(const char** (*halmplane_get_tx_array_names)(), ftag);
  
  halmplane_get_tx_array_names = (const char** (*)()) hal_loader->get_function(ftag);

  if(halmplane_get_tx_array_names)
  {
    std::cout << "wrapper " ;
    return halmplane_get_tx_array_names();
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

int halmplane_get_low_level_tx_endpoint_(const char* name, low_level_tx_endpoint_t* tx_endpoint)
{
  capture_source_as_str(int (*halmplane_get_low_level_tx_endpoint)(const char*, low_level_tx_endpoint_t*), ftag);
  
  halmplane_get_low_level_tx_endpoint = (int (*)(const char*, low_level_tx_endpoint_t*)) hal_loader->get_function(ftag);

  if(halmplane_get_low_level_tx_endpoint)
  {
    std::cout << "wrapper " ;
    return halmplane_get_low_level_tx_endpoint(name, tx_endpoint);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

int halmplane_get_low_level_tx_endpoints(low_level_tx_endpoint_t** tx_endpoints, int* n_endpoints)
{
  capture_source_as_str(int (*halmplane_get_low_level_tx_endpoints)(low_level_tx_endpoint_t**, int*), ftag);
  
  halmplane_get_low_level_tx_endpoints = (int (*)(low_level_tx_endpoint_t**, int*)) hal_loader->get_function(ftag);

  if(halmplane_get_low_level_tx_endpoints)
  {
    std::cout << "wrapper " ;
    return halmplane_get_low_level_tx_endpoints(tx_endpoints, n_endpoints);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;  
}

void wrapper_halmplane_exit()
{
  hal_loader->Hal_close();
}
