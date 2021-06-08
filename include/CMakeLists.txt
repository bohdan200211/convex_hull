file(GLOB_RECURSE HEADER_FILES
        *.hpp
        )

file(GLOB_RECURSE SOURCE_FILES
        *.cpp
        )



add_library(ConvexHull STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(ConvexHull PUBLIC Polygon)