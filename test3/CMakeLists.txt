cmake_minimum_required(VERSION 3.19)
project(bin_sort_tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(bin_sort_tree main.cpp Assistance.h BinarySortTree.h BinTreeNode.h LinkQueue.h Node.h)