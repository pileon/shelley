set(SHELLEY_TEST_SOURCE_FILES utility.cpp ../../include/shelley/utility.h ../../src/utility.cpp)
add_executable(shelley_test ${SHELLEY_TEST_SOURCE_FILES})
target_include_directories(shelley_test PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(shelley_test gtest gtest_main)
if (NOT STDLIBCXX_WITHOUT_LIBCXXABI)
    target_link_libraries(shelley_test c++abi)
endif()

add_test(NAME shelley_test
        COMMAND shelley_test)
