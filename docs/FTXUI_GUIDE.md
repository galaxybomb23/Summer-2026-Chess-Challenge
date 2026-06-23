**FTXUI Quick Development Guide**

- **Purpose:** Quick reference to use FTXUI in this project: how to build, run examples/docs, a minimal sample, and common tips.

**Setup**:
- **Configure the project (once online):**

  - Run the standard configure step to fetch FTXUI via FetchContent and prepare the build tree:

  ```bash
  cmake -S . -B build
  ```

- **Build everything (libraries, examples, docs when available):**

  ```bash
  cmake --build build --parallel "$(nproc)"
  ```

- **Notes for offline use:**
  - Enable examples and docs in `CMakeLists.txt` (already enabled in this repo). Configure while online so FetchContent clones FTXUI into `_deps/` before you go offline.
  - If you want generated HTML docs locally, install `doxygen` before configuring so CMake will enable docs generation.

**Running FTXUI examples and docs**
- Example binaries and documentation are produced inside the build tree under `_deps/ftxui-build` or `_deps/ftxui-src` depending on your CMake generator. To discover available example binaries quickly, run from the repo root:

```bash
find build -type f -executable -maxdepth 6 | grep -i ftxui || true
```

- If Doxygen was found at configure time, look for generated docs under `build` (search for `html` or `doxygen` directories).

**How to use FTXUI in your code (minimal example)**

Create a small C++ file (for example `src/ftxui_hello.cpp`) with the following content:

```cpp
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

int main() {
  auto screen = ScreenInteractive::TerminalOutput();

  auto renderer = Renderer([] {
    return vbox({
      text("Hello from FTXUI!"),
      separator(),
      text("Press q to quit") | center
    }) | border;
  });

  screen.Loop(renderer);
  return 0;
}
```

Then add this file to the `src/` directory and reconfigure/build. Our `CMakeLists.txt` already links the FTXUI libraries (`ftxui::screen`, `ftxui::dom`, `ftxui::component`) for the `summer_chess` target, so the new source will be compiled and linked automatically on the next configure/build.

**CMake notes (how this repo integrates FTXUI)**
- The repo uses `FetchContent` to fetch FTXUI (see `CMakeLists.txt`). CMake targets provided by FTXUI are available and used like:

```cmake
target_link_libraries(summer_chess PRIVATE
  ftxui::screen
  ftxui::dom
  ftxui::component
)
```

- Examples and docs are enabled in the project so you can browse the upstream examples offline after the dependency is fetched.

**Tips & Troubleshooting**
- Terminal compatibility: FTXUI assumes a UTF-8 terminal that supports ANSI sequences. On Windows prefer an environment like MSYS2/MinGW or the Windows Terminal with proper VT support.
- If your build fails with missing symbols, check that your source files are compiled as C++ (the repo forces C++ for `src/*.c|cpp` via CMake). Rename `.c` to `.cpp` if appropriate.
- If docs are missing after configure, install `doxygen` and re-run configure/build.
- To inspect FTXUI headers: they live under `_deps/ftxui-src/include/ftxui/` inside the build tree after FetchContent populates `_deps/`.

**Useful commands**
- Configure + build everything:

```bash
cmake -S . -B build
cmake --build build --parallel "$(nproc)"
```

- Build only examples (if you know the example target name):

```bash
cmake --build build --target <example-name>
```

- Run tests (this repo):

```bash
./run.sh -t
```

**References**
- FTXUI upstream: https://github.com/ArthurSonzogni/FTXUI
- FTXUI examples: check `build/_deps/ftxui-build/examples` after building with examples enabled.

---
Small, focused guide — if you want I can add several curated example programs from upstream into `examples/` here for offline reference, or a one-file quickstart that compiles without CMake.
