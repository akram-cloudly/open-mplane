#include "MplaneAld.h"
#include <iostream>

halmplane_error_t halmplane_ald_get_counters(
    halmplane_ald_communication_output_t* ald_status)
{
    std::cout << "halmplane_ald_get_counters() loading..." << std::endl;
    return NONE;
}

halmplane_error_t halmplane_ald_get_status(
    halmplane_ald_communication_output_t* ald_status)
{
    std::cout << "halmplane_ald_get_status() loading..." << std::endl;
    return NONE;
}

halmplane_error_t halmplane_ald_response(
     halmplane_ald_communication_input_s* ald_req, uint16_t msg_size)
{
    std::cout << "halmplane_ald_response() loading..." << std::endl;
    return NONE;
}

halmplane_error_t halmplane_ald_set_receive_mode(
    halmplane_ald_communication_input_s* ald_req, uint16_t msg_size)
{
    std::cout << "halmplane_ald_set_receive_mode() loading..." << std::endl;
    return NONE;    
}

halmplane_error_t halmplane_ald_request(
    halmplane_ald_communication_input_t* ald_req, uint16_t msg_size)
{
    std::cout << "halmplane_ald_request() loading..." << std::endl;
    return NONE;    
}