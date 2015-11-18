cmake_minimum_required(VERSION 3.3)
project(LibOPF_al)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include include/util)
link_libraries(m)

set(SOURCE_FILES
    src/OPF.c
    src/util/common.c
    src/util/gqueue.c
    src/util/realheap.c
    src/util/set.c
    src/util/sgctree.c
    src/util/subgraph.c)

add_executable(opf_distance ${SOURCE_FILES} src/opf_distance.c)
add_executable(opf_split ${SOURCE_FILES} src/opf_split.c)
add_executable(opf_train ${SOURCE_FILES} src/opf_train.c)
add_executable(opf_learn ${SOURCE_FILES} src/opf_learn.c)
add_executable(opf_classify ${SOURCE_FILES} src/opf_classify.c)
add_executable(opf_accuracy ${SOURCE_FILES} src/opf_accuracy.c)
