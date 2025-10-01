cmake_minimum_required(VERSION 3.16)
project(Markov_Chain_For_Shitposting LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
file(GLOB SOURCES 

    ${PROJECT_ROOT}/Unit_Test/src_test/*.cpp
    ${PROJECT_ROOT}/src/*.cpp
    ${PROJECT_ROOT}/*.cpp
)

add_executable(Markov_Chain_For_Shitposting ${SOURCES})

target_include_directories(Markov_Chain_For_Shitposting PRIVATE
    ${PROJECT_ROOT}/src
    ${PROJECT_ROOT}/Headers
    ${PROJECT_ROOT}/Unit_Test/Headers_test
 
)


target_compile_features(Markov_Chain_For_Shitposting PRIVATE cxx_std_17)

find_library(STDCXXFS_LIB stdc++fs)
find_library(CXXFS_LIB c++fs)

if(STDCXXFS_LIB)
    target_link_libraries(Markov_Chain_For_Shitposting PRIVATE ${STDCXXFS_LIB})
    message(STATUS "Linking with stdc++fs")
elseif(CXXFS_LIB)
    target_link_libraries(Markov_Chain_For_Shitposting PRIVATE ${CXXFS_LIB})
    message(STATUS "Linking with c++fs")
else()
    message(STATUS "No separate filesystem library needed")
endif()
