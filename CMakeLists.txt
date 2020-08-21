cmake_minimum_required(VERSION 3.15)

# detect whether wx has been added as a subproject
if(NOT DEFINED PROJECT_NAME)
    set(WX_NOT_SUBPROJECT ON)
endif()

include(cmake_includes/DefineProjectOnce.cmake)

define_project_once(wx)

project(wx CXX)

if(WX_NOT_SUBPROJECT)
    # This is the top-level project
    include(cmake_includes/Standalone.cmake)
    option(ENABLE_UNITY "Enable Unity builds of projects" OFF)
endif()

add_subdirectory(wxWidgets)

add_library(wxshim INTERFACE)
target_include_directories(wxshim INTERFACE ${PROJECT_SOURCE_DIR})
target_sources(wxshim INTERFACE wxshim.h)

if(ENABLE_UNITY)
  # Add for any project you want to apply unity builds for
  set_target_properties(wx PROPERTIES UNITY_BUILD ON)
endif()
