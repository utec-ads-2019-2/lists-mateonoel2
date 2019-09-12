cmake_minimum_required(VERSION 3.14)
project(lists-mateonoel2)

set(CMAKE_CXX_STANDARD 14)

add_executable(lists-mateonoel2 main.cpp circular.h forward.h iterator.h linked.h list.h node.h tester.h tester.cpp mocker.h mocker.cpp forward_iterator.h bidirectional_iterator.h)