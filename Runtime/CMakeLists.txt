add_executable(Runtime
    main.cpp
)

target_link_libraries(Runtime
    PRIVATE
        Engine
)