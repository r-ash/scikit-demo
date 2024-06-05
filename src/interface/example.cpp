#include <pybind11/pybind11.h>
#include <pybind11/eigen/tensor.h>
#include "add_eigen.hpp"

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");

    m.def(
        "add_tensor",
         &add_tensor,
        "A function that adds two tensors",
        py::return_value_policy::move);

    m.def(
        "get_tensor",
        []() { return new Eigen::Tensor<double, 3>(get_tensor()); },
        py::return_value_policy::move);

    py::class_<Data>(m, "Data")
        .def(py::init<TensorMap2, TensorMap2>())
        .def_readonly("tensor1", &Data::tensor1)
        .def_readonly("tensor2", &Data::tensor2);

    m.def(
        "add_tensors_py",
        &add_tensors_py,
        "A function that adds two tensors from a Data struct",
        py::return_value_policy::move);

    m.def(
        "add_tensors_in_place_py",
        &add_tensors_in_place_py,
        "A function that adds two tensors from a Data struct into a area of memory owned by python");
}