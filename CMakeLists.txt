cmake_minimum_required(VERSION 3.1.0)

IF(DEFINED CMAKE_BUILD_TYPE)
  set(
    CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING
    "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
  )
else()
  set(
    CMAKE_BUILD_TYPE Release CACHE STRING
    "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
  )
endif()

project(null_renderer_plugin)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(NULL_RENDERER_PLUGIN_COMPILER_FLAGS "")
if(MSVC)
  set(NULL_RENDERER_PLUGIN_COMPILER_FLAGS "/EHsc /MP")
  if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    set(NULL_RENDERER_PLUGIN_COMPILER_FLAGS "/EHsc /MP")
  endif()
endif()

# Dependencies
set(PROJECT_LINK_LIBRARY_DIRECTORIES
  ""
)

include_directories(ice_engine/ice_engine/deps/boost/include)
include_directories(ice_engine/ice_engine/deps/glew/include)
include_directories(ice_engine/ice_engine/deps/glm/include)
include_directories(ice_engine/ice_engine/deps/freeimage/include)

include_directories(ice_engine/ice_engine/include)

# Headers
include_directories(include)

# Source
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Flags
#set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${NULL_RENDERER_PLUGIN_COMPILER_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${NULL_RENDERER_PLUGIN_COMPILER_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${NULL_RENDERER_PLUGIN_COMPILER_FLAGS}")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} ${NULL_RENDERER_PLUGIN_COMPILER_FLAGS}")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} ${NULL_RENDERER_PLUGIN_COMPILER_FLAGS}")

add_library(null_renderer_plugin SHARED ${SOURCES})
