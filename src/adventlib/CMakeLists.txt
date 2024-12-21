add_library(adventlib STATIC)

file(GLOB_RECURSE adventlib_SRC "src/*")
target_sources(adventlib PRIVATE ${adventlib_SRC})
target_include_directories(adventlib PUBLIC "include")
target_compile_options(adventlib PRIVATE ${PROJECT_WARNING_FLAGS})
