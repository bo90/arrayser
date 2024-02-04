cmake_minimum_required(VERSION 3.27)
project(fig12_03 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(fig12_03
        ins_arr.c
        m_l/stackExample.c
        queue/que.c
        tree/threeTmp.c
        tree/threeTmp.c
        tree/threeTmp.c
        sort_choice/sortChoice.c
        sort_choice/sortChoice.c
        firstStep/stackStep.c
        libs/equalent/UF.h
        UnionPr/uinonClient.c
        UnionPr/unionFind.c
        uniter/u_q.cpp)
