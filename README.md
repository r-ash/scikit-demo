# scikit-demo

[![PyPI - Version](https://img.shields.io/pypi/v/scikit-demo.svg)](https://pypi.org/project/scikit-demo)
[![PyPI - Python Version](https://img.shields.io/pypi/pyversions/scikit-demo.svg)](https://pypi.org/project/scikit-demo)

-----

## Table of Contents

- [Prerequisites](#prerequisite)
- [Installation](#installation)
- [License](#license)

## Prerequisite

Install Eigen on your computer, on Mint/Ubuntu the easiest way for me was to install `libeigen3-dev`

```console
sudo apt-get install libeigen3-dev
```

My build and installation instructions use `hatch`. But this would also work with `pipx`

## Building and installing

This uses [scikit-build-core](https://scikit-build-core.readthedocs.io/en/latest/index.html) to build an example using pybind11 with Eigen.

With hatch and pip

```console
hatch shell
pip install .
```

with pipx
```console
pipx run build
```

## Running

```python
import example
import numpy as np

example.add(1, 2)

a = np.array([[1., 2., 3.],
              [4., 5., 6.]],
             order = 'F')
b = np.array([[9., 8., 7.],
              [6., 5., 4.]],
             order = 'F')
example.add_tensor(a, b)
```

## License

`scikit-demo` is distributed under the terms of the [MIT](https://spdx.org/licenses/MIT.html) license.
