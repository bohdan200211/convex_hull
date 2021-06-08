file(GLOB SOURCE_FILE
        *.cpp)

add_executable(MyTests ${SOURCE_FILE})

target_link_libraries(MyTests PRIVATE doctest_with_main ConvexHull)
