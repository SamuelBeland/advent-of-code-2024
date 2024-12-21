add_library(dayslib STATIC)

file(GLOB_RECURSE dayslib_SRC "src/*")
target_sources(dayslib PUBLIC ${dayslib_SRC})

target_include_directories(dayslib PUBLIC "include")
target_link_libraries(dayslib PUBLIC adventlib)
target_compile_options(dayslib PRIVATE ${PROJECT_WARNING_FLAGS})
