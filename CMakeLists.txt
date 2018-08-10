cmake_minimum_required(VERSION 3.1.0)
project(artifact VERSION 0.1.0)

include(CTest)
include(GNUInstallDirs)
include(GenerateExportHeader)

add_library(Artifact
  include/artifact/artifact.h
  src/artifact_private.h
  src/artifact.c
)

target_include_directories(Artifact
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

generate_export_header(Artifact)
target_sources(Artifact PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/artifact_export.h)

set_target_properties(Artifact PROPERTIES
  OUTPUT_NAME artifact
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
  C_VISIBILITY_PRESET hidden
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
