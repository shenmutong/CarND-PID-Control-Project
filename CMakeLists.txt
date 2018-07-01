project(PID)

cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++11)


set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")
SET(CMAKE_BUILD_TYPE "Debug")  
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")  
set(sources src/PID.cpp src/main.cpp)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 

include_directories(/usr/local/opt/openssl/include)
link_directories(/usr/local/opt/openssl/lib)
link_directories(/usr/local/Cellar/libuv/1*/lib)

endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 


add_executable(pid ${sources})

target_link_libraries(pid z ssl uv uWS)
