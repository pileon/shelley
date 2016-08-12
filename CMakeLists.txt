cmake_minimum_required(VERSION 3.5)
project(shelley
        VERSION 0.1.1
        LANGUAGES CXX C)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")

include(CheckCXXCompilerFlag)

# Check for supported warning flags
check_cxx_compiler_flag(-Wall HAVE_FLAG_WALL)
if(HAVE_FLAG_WALL)
    list(APPEND COMPILER_OPTIONS -Wall)
endif()
check_cxx_compiler_flag(-Wextra HAVE_FLAG_WEXTRA)
if(HAVE_FLAG_WEXTRA)
    list(APPEND COMPILER_OPTIONS -Wextra)
endif()
check_cxx_compiler_flag(-Weffc++ HAVE_FLAG_WEFFCXX)
if(HAVE_FLAG_WEFFCXX)
    list(APPEND COMPILER_OPTIONS -Weffc++)
endif()
check_cxx_compiler_flag(-Wpedantic HAVE_FLAG_WPEDANTIC)
if(HAVE_FLAG_WPEDANTIC)
    list(APPEND COMPILER_OPTIONS -Wpedantic)
else()
    check_cxx_compiler_flag(-pedantic HAVE_FLAG_PEDANTIC)
    if(HAVE_FLAG_PEDANTIC)
        list(APPEND COMPILER_OPTIONS -pedantic)
    endif()
endif()
check_cxx_compiler_flag(-Wimplicit-fallthrough HAVE_FLAG_WIMPLICIT_FALLTHROUGH)
if(HAVE_FLAG_WIMPLICIT_FALLTHROUGH)
    list(APPEND COMPILER_OPTIONS -Wimplicit-fallthrough)
endif()

# Check for standard to use
check_cxx_compiler_flag(-std=c++17 HAVE_FLAG_STD_CXX17)
if(HAVE_FLAG_STD_CXX17)
    list(APPEND COMPILER_OPTIONS -std=c++17)
else()
    check_cxx_compiler_flag(-std=c++1z HAVE_FLAG_STD_CXX1Z)
    if(HAVE_FLAG_STD_CXX1Z)
        list(APPEND COMPILER_OPTIONS -std=c++1z)
    else()
        check_cxx_compiler_flag(-std=c++14 HAVE_FLAG_STD_CXX14)
        if(HAVE_FLAG_STD_CXX14)
            list(APPEND COMPILER_OPTIONS -std=c++14)
        else()
            message(FATAL " Need a compiler capable of at least C++14")
        endif()
    endif()
endif()

check_cxx_compiler_flag(-stdlib=libc++ HAVE_FLAG_STDLIB_LIBCXX)

# Check if we can build with `stdlib=libc++` without linking with `-lc++abi`
if(HAVE_FLAG_STDLIB_LIBCXX)
    # Check that libc++ actually exists
    set(OLD_CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_FLAGS})
    set(CMAKE_REQUIRED_FLAGS "-stdlib=libc++")
    CHECK_CXX_SOURCE_COMPILES(
            "#include <iostream>
            int main()
            {
                std::cout << 'x';
            }"
            STDLIBCXX_WITHOUT_LIBCXXABI
            FAIL_REGEX "libc\\\\+\\\\+abi\\\\.so")
    set(CMAKE_REQUIRED_FLAGS ${OLD_CMAKE_REQUIRED_FLAGS})
endif()

if(HAVE_FLAG_STDLIB_LIBCXX)
    list(APPEND COMPILER_OPTIONS -stdlib=libc++)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
endif()

# Check for other miscelaneous flags
check_cxx_compiler_flag(-pipe HAVE_FLAG_PIPE)
if(HAVE_FLAG_PIPE)
    list(APPEND COMPILER_OPTIONS -pipe)
endif()

find_package(Threads)
if(Threads_FOUND)
    check_cxx_compiler_flag(-pthread HAVE_FLAG_PTHREAD)
    if(HAVE_FLAG_PTHREAD)
        list(APPEND COMPILER_OPTIONS -pthread)
    endif()
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")
    # TODO: Add the pthread linker library?
endif()

add_compile_options(${COMPILER_OPTIONS})
string(REPLACE ";" " " CMAKE_REQUIRED_FLAGS "${COMPILER_OPTIONS}")

configure_file(${CMAKE_SOURCE_DIR}/include/shelley/autoconf.h.in ${CMAKE_SOURCE_DIR}/include/shelley/autoconf.h)

add_subdirectory(src)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
