#pragma once

#include <unsupported/Eigen/CXX11/Tensor>
#include <iostream>

using Tensor2 = Eigen::Tensor<double, 2>;
using TensorMap2 = Eigen::TensorMap <Eigen::Tensor<double, 2>>;

// Example of a simple add, takes two TensorMaps (data owned by Python)
// and returns a new Tensor.
Tensor2 add_tensor(const TensorMap2& a, const TensorMap2& b) {
  // Assuming these are the same dimensions
  Eigen::Tensor<double, 2> result = a + b;
  return result;
}

template <typename M>
void reset_tensor(M &x) {
    for (int i = 0; i < x.dimension(0); i++) {
        for (int j = 0; j < x.dimension(1); j++) {
            for (int k = 0; k < x.dimension(2); k++) {
                x(i, j, k) = i * (5 * 2) + j * 2 + k;
            }
        }
    }
}

Eigen::Tensor<double, 3> &get_tensor() {
    static Eigen::Tensor<double, 3> *x;

    if (!x) {
        x = new Eigen::Tensor<double, 3>(3, 5, 2);
        reset_tensor(*x);
    }

    return *x;
}

struct Data {
    TensorMap2 tensor1;
    TensorMap2 tensor2;
};

// Example of a simple add, takes a struct containing TensorMaps and returns
// a tensor
Tensor2 add_tensors(const Data& data) {
    // Assuming these are the same dimensions
    return data.tensor1 + data.tensor2;
};

Tensor2 add_tensors_py(pybind11::dict dict) {
    TensorMap2 tensor1 = dict["tensor1"].cast<TensorMap2>();
    TensorMap2 tensor2 = dict["tensor2"].cast<TensorMap2>();

    const Data data = {tensor1, tensor2};
    return add_tensors(data);
};

// Example of a simple add, takes a struct containing TensorMaps
// and modified python data in palce
void add_tensors_in_place(const Data& input, TensorMap2 out) {
    out = input.tensor1 + input.tensor2;
};

void add_tensors_in_place_py(pybind11::dict input, TensorMap2 out) {
    TensorMap2 tensor1 = input["tensor1"].cast<TensorMap2>();
    TensorMap2 tensor2 = input["tensor2"].cast<TensorMap2>();

    const Data data = {tensor1, tensor2};
    return add_tensors_in_place(data, out);
};