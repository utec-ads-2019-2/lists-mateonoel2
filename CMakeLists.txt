cmake_minimum_required(VERSION 3.14)
project(lists-mateonoel2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(iterators)
include_directories(mock)
include_directories(test)

add_executable(
        lists-mateonoel2
        main.cpp
        circular.h
        forward.h
        iterator.h
        linked.h
        list.h
        node.h
        test/tester.h
        test/tester.cpp
        mock/mocker.h
        mock/mocker.cpp
        iterators/forward_iterator.h
        iterators/bidirectional_iterator.h
        )