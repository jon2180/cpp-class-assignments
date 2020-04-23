cmake_minimum_required(VERSION 3.15)
project(class_management_system)

set(CMAKE_CXX_STANDARD 17)

set(RES_DIR res)

set(SFML_BUILD_OUTPUT "${CMAKE_BINARY_DIR}")

add_executable(class_management_system
        src/models/GradeTable.cpp
        src/models/GradeTable.h
        src/models/Student.cpp
        src/models/Student.h
        src/models/SystemConfiguration.cpp
        src/models/SystemConfiguration.h
        src/Controller.cpp
        src/Controller.h
        src/Login.cpp
        src/Login.h
        src/View.cpp
        src/View.h
        src/main.cpp
        )

set_target_properties(class_management_system PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${SFML_BUILD_OUTPUT}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${SFML_BUILD_OUTPUT}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${SFML_BUILD_OUTPUT}/bin"
        )


install(DIRECTORY res/doc/ DESTINATION ${SFML_BUILD_OUTPUT}/doc)