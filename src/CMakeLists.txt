add_executable(MyMain main.cpp)
add_executable(MyMain1 main1.cpp)

target_link_libraries(MyMain PRIVATE ConvexHull)
target_link_libraries(MyMain1 PRIVATE ConvexHull)