set(DUMMY_SOURCE_FILES dummy.cpp)
add_executable(dummy ${DUMMY_SOURCE_FILES})
target_link_libraries(dummy gtest gtest_main)
if (NOT STDLIBCXX_WITHOUT_LIBCXXABI)
    target_link_libraries(dummy c++abi)
endif()

add_test(NAME dummy
        COMMAND dummy)
