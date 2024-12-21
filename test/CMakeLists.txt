add_executable(tests)
file(GLOB_RECURSE tests_SRC "*.cpp")
target_sources(tests PRIVATE ${tests_SRC})
target_link_libraries(tests PRIVATE dayslib Catch2::Catch2WithMain)
