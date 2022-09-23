#include <pybind11/embed.h>
#include "sv_export.c"

int write_reg_c(int addr, int data) {
    write_reg(addr,data);
}

PYBIND11_MODULE(py2sv, m) {
    m.doc() = "write register plugin";
    m.def("write_reg", &write_reg_c, "Write data to address");
}