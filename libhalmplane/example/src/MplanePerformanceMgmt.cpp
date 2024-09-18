/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "FbOruPerformanceMgmt.h"
// #include "MplanePerformanceMgmt.h"
#include <iostream> 
// #include "IMeasRssi.h"


// using Mplane::IMeasRssi;
// using Mplane::Power;

int halmplane_registerOranPerfMeasCallback(halmplane_oran_perf_meas_cb_t callback) {
    std::cout << "halmplane_registerOranPerfMeasCallback() loading..." << std::endl;
    return 0;
}

int halmplane_getRssi(uint8_t interface, double *rssiValue) {
    // std::
    // return fb_oru_getRssi(interface, rssiValue);
    std::cout << "halmplane_getRssi() loading..." << std::endl;
    return 0;
}

// int halmplane_activateEpeMeasObjects(
//     int config, int cb)
// {
//     std::cout << "halmplane_activateEpeMeasObjects() loading..." << std::endl;
//     return 0;
// }

int halmplane_activateEpeMeasObjects(
    epe_measurement_objects_t config, halmplane_epe_meas_cb_t cb)
{
    std::cout << "halmplane_activateEpeMeasObjects() loading..." << std::endl;
    return 0;
}   

int halmplane_configPerfMeasurementParams(
    performance_measurement_params_t* config)
{
    std::cout << "halmplane_configPerfMeasurementParams() loading..." << std::endl;
    return 0;
}

int halmplane_activateTransceiverMeasObjects(
    transceiver_measurement_objects_t config,
    halmplane_transceiver_meas_cb_t cb)
{
    std::cout << "halmplane_activateTransceiverMeasObjects() loading..." << std::endl;
    return 0;
}

int halmplane_activateRxWindowMeasObjects(
    rx_window_measurement_objects_t config,
    halmplane_rx_window_meas_cb_t cb)
{
    std::cout << "halmplane_activateRxWindowMeasObjects() loading..." << std::endl;
    return 0;
}

int halmplane_activateTxMeasObjects(
    const tx_measurement_objects_t config,
    halmplane_tx_stats_meas_cb_t cb)
{
    std::cout << "halmplane_activateTxMeasObjects() loading..." << std::endl;
    return 0;    
}

const halmplane_oran_perf_meas_cb_t get_perf_meas_cb_ptr(void)
{
    MplanePerfMeasInfo fb_oru_perfMeasInfo;
    std::cout << "get_perf_meas_cb_ptr() loading..." << std::endl;
    return fb_oru_perfMeasInfo.cb_ptr;
}