cmake_minimum_required(VERSION 3.1.0)
project(artifact VERSION 0.1.0)

include(CTest)
include(GNUInstallDirs)
include(GenerateExportHeader)
include(CMakePackageConfigHelpers)

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


set(Artifact_HDRS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/artifact/artifact.h
  ${CMAKE_CURRENT_BINARY_DIR}/artifact_export.h
)
set_target_properties(Artifact PROPERTIES
  OUTPUT_NAME artifact
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
  C_VISIBILITY_PRESET hidden
  PUBLIC_HEADER "${Artifact_HDRS}"
)

install(TARGETS Artifact
  EXPORT ArtifactConfig
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  FRAMEWORK DESTINATION ${CMAKE_INSTALL_PREFIX}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/artifact
)
if(WIN32)
    set(CMAKE_INSTALL_PACKAGEDIR cmake)
else()
    set(CMAKE_INSTALL_PACKAGEDIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
endif()
install(
    EXPORT ArtifactConfig
    NAMESPACE Artifact::
    DESTINATION ${CMAKE_INSTALL_PACKAGEDIR}
)
write_basic_package_version_file(ArtifactConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/ArtifactConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_PACKAGEDIR}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
