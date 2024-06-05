from example import add, add_tensor
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
