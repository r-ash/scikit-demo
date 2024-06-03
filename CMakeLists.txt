cmake_minimum_required(VERSION 3.15...3.26)
project(${SKBUILD_PROJECT_NAME} LANGUAGES CXX)

set(PYBIND11_NEWPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

# Add Eigen
find_package(Eigen3 3.4 REQUIRED NO_MODULE)

pybind11_add_module(example src/interface/example.cpp)
target_include_directories(example PRIVATE src/cpp)
target_link_libraries (example PRIVATE Eigen3::Eigen)

install(TARGETS example LIBRARY DESTINATION .)
