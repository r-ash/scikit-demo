# scikit-demo

[![Project Status: Concept – Minimal or no implementation has been done yet, or the repository is only intended to be a limited example, demo, or proof-of-concept.](https://www.repostatus.org/badges/latest/concept.svg)](https://www.repostatus.org/#concept)

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

## Useful hatch commands

```console
hatch shell
hatch run install
hatch run test
hatch run install_and_test
```

## Building and installing

This uses [scikit-build-core](https://scikit-build-core.readthedocs.io/en/latest/index.html) to build an example using pybind11 with Eigen.

With hatch

```console
hatch run install
```

with pipx
```console
pipx run build
```

## Running

You can run the tests with

```console
hatch run install_and_test
```

or, if you haven't modified the C++
```console
hatch run test
```

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
