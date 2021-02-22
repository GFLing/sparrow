
set(SOURCE_FILES
    main.cpp
    webserver/webserver.h
    webserver/webserver.cpp
    webserver/threadpool.h
    webserver/threadpool.cpp
    webserver/sync.h
    webserver/sync.cpp

    util/config_parser.h
    util/config_parser.cpp
    util/log.h
    )


find_package(Threads REQUIRED)

set(LINK_LIBS
    Threads::Threads
)

add_executable(sparrow
    ${SOURCE_FILES}
    )
target_link_libraries(sparrow ${LINK_LIBS})
target_include_directories(sparrow PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})