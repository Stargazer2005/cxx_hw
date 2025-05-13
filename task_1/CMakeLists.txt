cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)

project(user_management_system)

add_executable(user_management_system
    main.cpp
    user.cpp
    group.cpp
    user_manager.cpp
    group_manager.cpp
    command_processor.cpp
)