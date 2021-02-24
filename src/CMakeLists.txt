
set(SOURCE_FILES
    main.cpp
    translayer/tcpserver.h
    translayer/tcpserver.cpp

    base/threadpool.h
    base/threadpool.cpp

    util/config_parser.h
    util/config_parser.cpp
    )

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
find_package(glog REQUIRED)

set(LINK_LIBS
    Threads::Threads
    glog::glog
)

add_executable(sparrow
    ${SOURCE_FILES}
    )
target_link_libraries(sparrow ${LINK_LIBS})
target_include_directories(sparrow PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


#-----unittest-----
set(UNITTEST_FILES
    base/inet_address.cpp    
    base/inet_address.h
    base/inet_address_unittest.cpp
)

add_executable(unittest
    unittest_main.cpp
    ${UNITTEST_FILES}
)

target_link_libraries(unittest
    GTest::GTest
    glog::glog
)
target_include_directories(unittest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})