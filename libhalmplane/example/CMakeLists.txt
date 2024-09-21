string(CONCAT SRC
  "src/MplaneInterfaces.cpp;"
  "src/APIregistration.cpp;"
  "src/MplaneProcessingElements.cpp;"
  "src/MplaneUplaneConf.cpp;"
  "src/HalMplane.cpp;"
  # "src/MplaneAlarms.cpp;"
  # "src/MplaneEcpri.cpp;"
  # "src/MplanePerformanceMgmt.cpp;"
  # "src/MplaneExternalio.cpp;"
  # "src/MplaneHardware.cpp;"
  # "src/MplaneFan.cpp;"
  # "src/MplaneAntennaCalibration.cpp;"
  # "src/MplaneAld.cpp;"
  # "src/MplaneBeamforming.cpp;"
  # "src/MplaneSync.cpp;"
  # "src/MplaneDelayMgmt.cpp;"
  # "src/MplaneModuleCapability.cpp;"
  # "src/MplaneSupervision.cpp;"
  # "src/MplaneTransceiver.cpp; "
)

include_directories(inc)

if(("${CONTEXT}" STREQUAL "YOCTO") OR ("${CONTEXT}" STREQUAL "MODULE"))
  list(TRANSFORM SRC PREPEND "example/")
  target_sources(halmplane PRIVATE ${SRC})
else()
  add_sources(SOURCES ${SRC})
endif()
