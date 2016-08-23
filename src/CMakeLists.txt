set(SOURCE_FILES shelley.cpp ../include/shelley/utility.h utility.cpp)
add_executable(shelley ${SOURCE_FILES})
target_include_directories(shelley
        PUBLIC ../include)

add_custom_target(valgrind
        COMMAND valgrind --leak-check=full ${CMAKE_BINARY_DIR}/tests/shelley/shelley_test
        DEPENDS shelley_test)
