set(SOURCE_FILES shelley.cpp ../include/shelley/utility.h utility.cpp)
add_executable(shelley ${SOURCE_FILES})
target_include_directories(shelley
        PUBLIC ../include)
