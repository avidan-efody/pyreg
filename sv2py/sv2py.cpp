#include <iostream>
#include <memory>
#include <pybind11/embed.h>

namespace py = pybind11;
using namespace std;

py::object test;

unique_ptr<py::scoped_interpreter> guard = nullptr;

void check_interpreter() {
    if (!guard) guard = unique_ptr<py::scoped_interpreter>(new py::scoped_interpreter());
}

extern "C" {
__attribute__((visibility("default"))) int init_test(char* py_module, char* py_reg_test_name)
{    
    check_interpreter();
    py::module register_tests = py::module::import(py_module);
    test = register_tests.attr(py_reg_test_name)();
    std::cout << "sv2py : loaded " << py_reg_test_name << " from " << py_module << std::endl;
    return 0;
}

__attribute__((visibility("default"))) int start_test()
{   
    check_interpreter(); 
    std::cout << "sv2py : starting test" << std::endl;
    py::object result = test.attr("start_test")();
    return 0;
}
}


