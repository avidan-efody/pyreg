project(sv2py)
cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)	

include(FetchContent)
FetchContent_Declare(
	pybind11
	GIT_REPOSITORY https://github.com/pybind/pybind11.git
	GIT_TAG        v2.6.2
	GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(pybind11)

add_library(sv2py SHARED sv2py.cpp)
target_link_libraries(sv2py PRIVATE pybind11::embed)



