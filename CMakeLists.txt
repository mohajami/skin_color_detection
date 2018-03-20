cmake_minimum_required(VERSION 3.0)

project(OpenCV_VideoMaker CXX)

if (Boost_FOUND)
	add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})
	set (BOOST_ROOT = "C:/libs/boost_1_64_0")
	set (BOOST_LIBRARYDIR = "C:/libs/boost_1_64_0/lib64-msvc-14.0")
endif(Boost_FOUND)

if(Boost_FOUND)
	find_package(Boost 1.64.0 REQUIRED)
  include_directories(include/ ${Boost_INCLUDE_DIRS})
  link_directories(${BOOST_LIBRARYDIR})
endif(Boost_FOUND)

# Find the OpenCV library
find_package(OpenCV REQUIRED)

include_directories(include/ ${OpenCV_INCLUDE_DIRS})

add_executable(videoMaker src/videoMaker_main.cpp)
target_link_libraries(videoMaker ${OpenCV_LIBS})

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
string( TOUPPER "${PROJECT_NAME}" PRJ_NAME_UPPER )
string( REPLACE "-" "_" PRJ_NAME_UPPER ${PRJ_NAME_UPPER} )

get_property( INCLUDE_DIRS DIRECTORY PROPERTY INCLUDE_DIRECTORIES )
set( ${PRJ_NAME_UPPER}_INCLUDE_DIRS ${INCLUDE_DIRS} CACHE INTERNAL "${PROJECT_NAME}: include directories" FORCE )

get_property( LINK_DIRS DIRECTORY PROPERTY LINK_DIRECTORIES )
set( ${PRJ_NAME_UPPER}_LINK_DIRS ${LINK_DIRS} CACHE INTERNAL "${PROJECT_NAME}: link directories" FORCE )