from example import *
import numpy as np


def test_add():
    assert add(1, 2) == 3


def test_add_tensor():
    a = np.array([[1., 2., 3.],
                  [4., 5., 6.]],
                 order='F')
    b = np.array([[9., 8., 7.],
                  [6., 5., 4.]],
                 order='F')
    expected = np.array([[10., 10., 10.],
                         [10., 10., 10.]],
                        order='F')
    assert (add_tensor(a, b) == expected).all()


def test_add_tensors():
    a = np.array([[1., 2., 3.],
                  [4., 5., 6.]],
                 order='F')
    b = np.array([[9., 8., 7.],
                  [6., 5., 4.]],
                 order='F')
    tensor_dict = {
        "tensor1": a,
        "tensor2": b
    }
    expected = np.array([[10., 10., 10.],
                         [10., 10., 10.]],
                        order='F')
    assert (add_tensors_py(tensor_dict) == expected).all()


def test_add_tensors_in_place():
    a = np.array([[1., 2., 3.],
                  [4., 5., 6.]],
                 order='F')
    b = np.array([[9., 8., 7.],
                  [6., 5., 4.]],
                 order='F')
    tensor_dict = {
        "tensor1": a,
        "tensor2": b
    }
    out = np.array([[0., 0., 0.],
                   [0., 0., 0.]],
                   order='F')
    expected = np.array([[10., 10., 10.],
                         [10., 10., 10.]],
                        order='F')
    add_tensors_in_place_py(tensor_dict, out)
    assert (out == expected).all()


def test_add_tensors_large():
    # Create large input arrays of size 1000x1000
    a = np.arange(1, 1001).reshape(1000, 1) @ np.ones((1, 1000))
    b = np.arange(1000, 0, -1).reshape(1000, 1) @ np.ones((1, 1000))

    # Ensure the arrays are in Fortran order as specified
    a = np.asfortranarray(a)
    b = np.asfortranarray(b)

    tensor_dict = {
        "tensor1": a,
        "tensor2": b
    }

    # Expected result is the sum of the two matrices
    expected = a + b

    # Output array
    out = np.zeros((1000, 1000), order='F')

    # Call the function and update 'out' in place
    add_tensors_in_place_py(tensor_dict, out)

    # Assert that the result is as expected
    assert np.all(out == expected), "The result does not match the expected output."

    out2 = add_tensors_py(tensor_dict)
    assert np.all(out == out2)