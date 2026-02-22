# Microduino PlatformIO Setup

This repository is a PlatformIO-based setup for Microduino / mCookie examples and modules.

## Important Sources

### Tutorials
- Microduino mCookie Expert Kit Tutorials (archived):
  - https://web.archive.org/web/20241014024312/https://wiki.microduinoinc.com/MCookie_Expert_Kit_Tutorials
- GitHub tutorial example (`light_led`):
  - https://github.com/Microduino/Microduino_Tutorials/tree/master/MCookie_Tutorial/light_led

### Source Code
- Microduino IDE Support release:
  - https://github.com/wasdpkj/Microduino-IDE-Support/releases/tag/1.8.10-1.0

## Build & Upload

This project uses PlatformIO with the environment defined in `platformio.ini`:

- Environment: `mcookie`
- Platform: `atmelavr`
- Board: `uno`
- Framework: `arduino`

### Prerequisites
- Install [PlatformIO Core](https://docs.platformio.org/en/latest/core/installation/index.html) or use the VS Code PlatformIO extension.

### Build
From the project root:

```bash
pio run -e mcookie
```

### Upload
Connect your board, then run:

```bash
pio run -e mcookie -t upload
```

### Serial Monitor

```bash
pio device monitor -b 9600
```

## Using Example Sketches

The default build compiles `src/main.cpp`.

To run a sketch from `examples/`, copy or adapt the sketch code into `src/main.cpp`, then build/upload again.
