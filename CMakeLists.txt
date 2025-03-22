    cmake_minimum_required(VERSION 3.10)

    project(LinkedList)

    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED True)

    include_directories(include)

    # Find all .cpp files in src/
    file(GLOB SRC_FILE src/*.cpp) 

    # Create the executable
    add_executable(${PROJECT_NAME} ${SRC_FILE})

    # Include directory for header files
    target_include_directories(${PROJECT_NAME} PUBLIC include)

