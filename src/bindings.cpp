#include "Drone.h"
#include <pybind11/pybind11.h>
#include <string>

using namespace Matrice;
using namespace DJI::OSDK;

namespace py = pybind11;

PYBIND11_MODULE(djisdkpy, m) {
    py::class_<Drone>(m, "Drone")
        .def(py::init())
        .def("getMainCameraStream", &Drone::getMainCameraStream);
}

