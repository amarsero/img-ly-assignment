cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("img-ly-assignment")

add_executable (img-ly-assignment "src/main.cpp" "src/compute_pipeline.cpp" "src/pipeline_stage.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET img-ly-assignment PROPERTY CXX_STANDARD 20)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(img-ly-assignment PRIVATE -Wall -Wextra -Wpedantic -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(img-ly-assignment PRIVATE /W4 /Wall /WX)
endif()
