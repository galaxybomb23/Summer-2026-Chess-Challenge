#!/usr/bin/env bash
set -euo pipefail

# Setup directories
root_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
build_dir="$root_dir/build"

# Parallel Compilation Configuration
# Leverages all available hardware processing threads unless PARALLEL environment variable exists.
CPU_CORES=$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 2)
parallel="${PARALLEL:-$CPU_CORES}"

# Function to display usage help
show_help() {
    cat << EOF
Usage: ./run.sh [OPTIONS]

A helper script to manage builds, run tests, and execute the C++ Chess Challenge application.

Options:
  -c, --clean    Wipes out the existing build directory for a fresh compilation.
  -t, --test     Builds and runs the unit test suite (summer_chess_tests) via ctest.
  -h, --help     Displays this help message and exits.

Environment Variables:
  PARALLEL       Number of parallel compilation jobs (Defaults to system core count: $parallel).
EOF
}

# Parse arguments
CLEAN_BUILD=0
RUN_TESTS=0

while [[ $# -gt 0 ]]; do
    case "$1" in
        -c|--clean)
            CLEAN_BUILD=1
            shift
            ;;
        -t|--test)
            RUN_TESTS=1
            shift
            ;;
        -h|--help)
            show_help
            exit 0
            ;;
        *)
            echo "Error: Unknown option '$1'" >&2
            show_help >&2
            exit 1
            ;;
    esac
done

# Handle clean build flag
if [ "$CLEAN_BUILD" -eq 1 ] && [ -d "$build_dir" ]; then
    echo "Cleaning build directory..."
    rm -rf "$build_dir"
fi

# Configure CMake if CMakeCache doesn't exist
if [ ! -f "$build_dir/CMakeCache.txt" ]; then
    echo "Configuring project..."
    # Forces parallel processing capabilities during CMake generation phases
    cmake -S "$root_dir" -B "$build_dir" -DCMAKE_BUILD_TYPE=Debug
fi

# Build and execute using maximum parallel allocation options
if [ "$RUN_TESTS" -eq 1 ]; then
    echo "Building and running tests (using $parallel parallel jobs)..."
    cmake --build "$build_dir" --target summer_chess_tests --parallel "$parallel"
    cd "$build_dir" && ctest --output-on-failure --parallel "$parallel"
else
    echo "Building and running application (using $parallel parallel jobs)..."
    cmake --build "$build_dir" --target summer_chess --parallel "$parallel"
    echo "------------------------------------------------"
    "$build_dir/summer_chess"
fi
