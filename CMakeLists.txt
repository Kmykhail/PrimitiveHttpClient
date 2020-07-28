cmake_minimum_required(VERSION 3.10)
project(PrimitiveHttpClient)

set(CMAKE_CXX_STANDARD 17)

add_executable(PrimitiveHttpClient main.cpp PrimitiveHttpClient.cpp PrimitiveHttpClient.h)

target_link_libraries(PrimitiveHttpClient -lcurl)