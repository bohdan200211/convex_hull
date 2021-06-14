set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost COMPONENTS system regex)


if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(WebServerTest ServerApp.cpp ${HEADER_FILES})
    target_link_libraries(WebServerTest ${Boost_LIBRARIES} ConvexHull)
endif()

include_directories(Include)
