cmake_minimum_required(VERSION 3.17)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2 main.cpp DynamicArray.cpp DynamicArray.h LinkedList.cpp LinkedList.h Sequence.h LinkedListSequence.h DynamicArraySequence.h Tests.cpp Tests.h Vector.h menu.cpp menu.h)