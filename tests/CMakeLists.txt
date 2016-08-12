cmake_policy(PUSH)
add_subdirectory(googletest)
cmake_policy(POP)

include_directories(${gtest_SOURCE_DIR}/include)

add_subdirectory(shelley)
