cmake_minimum_required(VERSION 3.20)
project(Summer2026ChessChallenge LANGUAGES CXX)

include(FetchContent)

# ==============================================================================
# 1. COMPILER & PERFORMANCE OPTIMIZATIONS
# ==============================================================================

# Enable compiler caching automatically if available on the system
find_program(CCACHE_PROGRAM ccache)

if(CCACHE_PROGRAM)
  set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
endif()

# Strict C++20 Standard Configuration
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Strip down external library targets to minimize overhead and build times
set(FTXUI_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(FTXUI_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(FTXUI_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

# Prevent CMake from wasting time trying to ping GitHub for updates if local files exist
set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "" FORCE)

# ==============================================================================
# 2. OFFLINE-FIRST DEPENDENCY MANAGEMENT (FTXUI & Google Test)
# ==============================================================================

# Define our secure local dependency cache directory
set(LOCAL_DEP_DIR "${CMAKE_SOURCE_DIR}/.dependencies")

# --- Fetch / Locate FTXUI ---
if(EXISTS "${LOCAL_DEP_DIR}/ftxui")
  message(STATUS "Found FTXUI locally at ${LOCAL_DEP_DIR}/ftxui")
  FetchContent_Declare(
    ftxui
    SOURCE_DIR "${LOCAL_DEP_DIR}/ftxui"
  )
else()
  message(STATUS "FTXUI local cache not found. Fetching from GitHub via Git...")
  FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG v5.0.0
  )
endif()

# --- Fetch / Locate Google Test ---
if(EXISTS "${LOCAL_DEP_DIR}/googletest")
  message(STATUS "Found Google Test locally at ${LOCAL_DEP_DIR}/googletest")
  FetchContent_Declare(
    googletest
    SOURCE_DIR "${LOCAL_DEP_DIR}/googletest"
  )
else()
  message(STATUS "Google Test local cache not found. Fetching from GitHub via Git...")
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
  )
endif()

# Make packages available locally
FetchContent_MakeAvailable(ftxui googletest)

# ==============================================================================
# 3. SOURCE FILE DISCOVERY
# ==============================================================================

# Dynamically gather project source and header files
file(GLOB_RECURSE summer_chess_sources CONFIGURE_DEPENDS
  src/*.c src/*.cc src/*.cpp src/*.cxx
)
file(GLOB_RECURSE summer_chess_headers CONFIGURE_DEPENDS
  include/*.h include/*.hh include/*.hpp include/*.hxx
)

# Create a separate list for the test target that does NOT include main.cpp
list(REMOVE_ITEM summer_chess_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# ==============================================================================
# 4. MAIN APPLICATION TARGET
# ==============================================================================

# For the actual game, we manually include src/main.cpp back in
add_executable(summer_chess ${summer_chess_sources} ${summer_chess_headers} src/main.cpp)
target_include_directories(summer_chess PRIVATE include)
target_link_libraries(summer_chess PRIVATE ftxui::screen ftxui::dom ftxui::component)

# Explicitly force C++ linkage properties on discovered source assets
set_source_files_properties(${summer_chess_sources} PROPERTIES LANGUAGE CXX)

# ==============================================================================
# 5. TEST ENVIRONMENT TARGET (GTest)
# ==============================================================================
enable_testing()
file(GLOB_RECURSE summer_chess_test_sources CONFIGURE_DEPENDS tests/*.cpp)

# Conditionally compile tests only if test source files exist
if(summer_chess_test_sources)
  # This now contains all your chess logic, but safely excludes the interactive main.cpp loop!
  add_executable(summer_chess_tests ${summer_chess_test_sources} ${summer_chess_sources})
  target_include_directories(summer_chess_tests PRIVATE include)
  target_link_libraries(summer_chess_tests PRIVATE gtest_main ftxui::screen ftxui::dom ftxui::component)

  include(GoogleTest)
  gtest_discover_tests(summer_chess_tests)
endif()
