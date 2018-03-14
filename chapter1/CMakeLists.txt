# CMakeList.txt : CMake project for vulkan2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


set_property( GLOBAL PROPERTY USE_FOLDERS ON )
set( CMAKE_SUPPRESS_REGENERATION true )

###############################################################
# Environment setup                                           #
###############################################################

if( CMAKE_BUILD_TYPE STREQUAL "" )
	set( CMAKE_BUILD_TYPE "debug" )
endif()

if( NOT DEFINED VK_USE_PLATFORM )
	if( WIN32 )
		set( VK_USE_PLATFORM "WIN32" )
	elseif( UNIX )
		set( VK_USE_PLATFORM "XCB" )
	endif()
endif()

if( VK_USE_PLATFORM STREQUAL "VK_USE_PLATFORM_WIN32_KHR" )
	set( CMAKE_C_FLAGS_RELWITHDEBINFO    "${CMAKE_C_FLAGS_RELWITHDEBINFO} /MT" )
	set( CMAKE_C_FLAGS_RELEASE           "${CMAKE_C_FLAGS_RELEASE} /MT" )
	set( CMAKE_C_FLAGS_DEBUG             "${CMAKE_C_FLAGS_DEBUG} /MTd" )
	set( CMAKE_CXX_FLAGS_RELWITHDEBINFO  "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MT" )
	set( CMAKE_CXX_FLAGS_RELEASE         "${CMAKE_CXX_FLAGS_RELEASE} /MT" )
	set( CMAKE_CXX_FLAGS_DEBUG           "${CMAKE_CXX_FLAGS_DEBUG} /MTd" )
	set( PLATFORM_LIBRARY                "" )
elseif( VK_USE_PLATFORM STREQUAL "XCB" )
	add_definitions( -std=c++11 )
	set( PLATFORM_LIBRARY dl xcb )
elseif( VK_USE_PLATFORM STREQUAL "XLIB" )
	add_definitions( -std=c++11 )
	set( PLATFORM_LIBRARY dl X11 )
endif()

if( CMAKE_BUILD_TYPE STREQUAL "debug" )
	add_definitions(-D_DEBUG)
endif()

add_definitions( -DVK_NO_PROTOTYPES )
add_definitions( -DVK_USE_PLATFORM_${VK_USE_PLATFORM}_KHR )


#############################################


file( GLOB COMMON "../Common/*.h" "../Common/*.inl" "../Common/*.cpp" )
add_library(JanixLibrary ${COMMON})
# Add source to this project's executable.
add_executable (vulkan2 "lesson03.cpp" "lesson03.h" "lesson05.cpp" "lesson05.h" ${COMMON})

