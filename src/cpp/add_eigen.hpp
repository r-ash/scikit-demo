#pragma once

#include <unsupported/Eigen/CXX11/Tensor>
#include <iostream>

using Tensor2 = Eigen::Tensor<double, 2>;
using TensorMap2 = Eigen::TensorMap <Eigen::Tensor<double, 2>>;

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