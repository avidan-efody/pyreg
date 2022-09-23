
cmake_minimum_required(VERSION 3.13)
project(reg_py2sv)
set(CMAKE_CXX_STANDARD 14)	

include(FetchContent)
FetchContent_Declare(
	pybind11
	GIT_REPOSITORY https://github.com/pybind/pybind11.git
	GIT_TAG        v2.6.2
	GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(pybind11)

pybind11_add_module(py2sv py2sv.cpp)
target_include_directories(py2sv PRIVATE /site/local/org-seg-tools-eda-cadence-xcelium--disk1/21.09.v002/tools.lnx86/include)
target_compile_features(py2sv PUBLIC cxx_std_14)
set_target_properties(py2sv PROPERTIES SUFFIX ".so")