# Copilot Context for this Repository

This is a PlatformIO project for Microduino/mCookie (Arduino AVR).

## Inspiration and reference code

- Use `examples/` as the primary source of implementation patterns and API usage.
- Start with `examples/00.mCookie_IBC/` and `examples/01.Basics/` for simple, known-good sketches.
- Reuse conventions from existing examples instead of introducing new project structures.

## Build and run commands

Run commands from the repository root.

- Build default environment:
  - `pio run -e mcookie`
- Upload to board:
  - `pio run -e mcookie -t upload`
- Serial monitor:
  - `pio device monitor -b 9600`

Current PlatformIO environment (`platformio.ini`):

- env: `mcookie`
- platform: `atmelavr`
- board: `uno`
- framework: `arduino`

## Noteworthy project details

- Active build entry point is `src/main.cpp`.
- Example sketches are not compiled automatically; port or adapt example code into `src/main.cpp` before building.
- Many module libraries are vendored under `lib/` with Microduino naming prefixes (for example `_01_`, `_07_`, `_10_`). Prefer these local libraries over adding new external dependencies unless required.
- Keep changes minimal and consistent with existing Arduino-style sketch code used across `examples/`.