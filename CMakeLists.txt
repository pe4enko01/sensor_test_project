cmake_minimum_required(VERSION 3.5.1)
#Название проекта
set(PACKAGE unitest)
project(${PACKAGE})
set(VERSION ${PROJECT_VERSION})
#################################################################################
#Устанавливаем флаги для компиляции
#################################################################################
set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage -fPIC")
set(GCC_COVERAGE_LINK_FLAGS    "-lgcov ")
set(CXX_EXTRA_FLAGS "-Wnon-virtual-dtor -Woverloaded-virtual -Woverflow -D_GLIBCXX_USE_NANOSLEEP -fstack-protector")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

#################################################################################
#подключаем библиотеки
#################################################################################
include(FindPkgConfig)
#подключаем uniset
pkg_check_modules(UNISET REQUIRED libUniSet2)
include_directories(${UNISET_INCLUDE_DIRS})
link_directories(${UNISET_LIBRARY_DIRS})
link_libraries(${UNISET})
#подключаем libUniSet2Extensions
pkg_check_modules(UNISETEXTENSION REQUIRED libUniSet2Extensions)
include_directories(${UNISETEXTENSION_INCLUDE_DIRS})
link_directories(${UNISETEXTENSION_LIBRARY_DIRS})
link_libraries(${UNISETEXTENSION})
#подключаем libUniSet2MBTCPMaster
pkg_check_modules(UNISETMBTCPMASTER REQUIRED libUniSet2MBTCPMaster)
include_directories(${UNISETMBTCPMASTER_INCLUDE_DIRS})
link_directories(${UNISETMBTCPMASTER_LIBRARY_DIRS})
link_libraries(${UNISETMBTCPMASTER})
#подключаем libUniSet2SharedMemory
pkg_check_modules(UNISETSHAREDMEMORY REQUIRED libUniSet2SharedMemory)
include_directories(${UNISETSHAREDMEMORY_INCLUDE_DIRS})
link_directories(${UNISETSHAREDMEMORY_LIBRARY_DIRS})
link_libraries(${UNISETSHAREDMEMORY})
#подключаем libUniSet2Algorithms
#pkg_check_modules(UNISETALGORITHMS REQUIRED libUniSet2Algorithms)
#include_directories(${UNISETALGORITHMS_INCLUDE_DIRS})
#link_directories(${UNISETALGORITHMS_LIBRARY_DIRS})
#link_libraries(${UNISETALGORITHMS})
#подключаем unisetUDP
pkg_check_modules(UNISETUNET REQUIRED libUniSet2UNetUDP)
include_directories(${UNISETUNET_INCLUDE_DIRS})
link_directories(${UNISETUNET_LIBRARY_DIRS})
link_libraries(${UNISETUNET})

########### библиотеки для графики ###############
#
#pkg_check_modules(GLADE REQUIRED libglade-2.0)
#include_directories(${GLADE_INCLUDE_DIRS})
#link_directories(${GLADE_LIBRARY_DIRS})
##
#pkg_check_modules(GLADEUI REQUIRED gladeui-1.0)
#include_directories(${GLADEUI_INCLUDE_DIRS})
#link_directories(${GLADEUI_LIBRARY_DIRS})
##
#pkg_check_modules(GLADEMM REQUIRED libglademm-2.4)
#include_directories(${GLADEMM_INCLUDE_DIRS})
#link_directories(${GLADEMM_LIBRARY_DIRS})
##
#pkg_check_modules(UNIWIDGETS REQUIRED uniwidgets2)
#include_directories(${UNIWIDGETS_INCLUDE_DIRS})
#link_directories(${UNIWIDGETS_LIBRARY_DIRS})
##
#pkg_check_modules(SETWIDGETS REQUIRED setwidgets2)
#include_directories(${SETWIDGETS_INCLUDE_DIRS})
#link_directories(${SETWIDGETS_LIBRARY_DIRS})

#################################################################################
#Сам проект
#################################################################################
add_subdirectory(docs)
add_subdirectory(src)
