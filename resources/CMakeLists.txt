set(INPUTS_DIR "${CMAKE_BINARY_DIR}/resources")

# Default inputs
file(COPY "days" DESTINATION "${INPUTS_DIR}")

# Test inputs
file(COPY "tests" DESTINATION "${INPUTS_DIR}")
