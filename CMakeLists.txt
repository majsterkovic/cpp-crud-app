cmake_minimum_required(VERSION 3.20)
project(projekt)

set(CMAKE_CXX_STANDARD 20)

add_executable(projekt main.cpp Device.cpp Device.h Notebook.cpp Notebook.h Smartband.cpp Smartband.h Base.cpp Base.h)
