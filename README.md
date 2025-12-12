# Image Viewer

A simple PPM (Portable Pixmap) image viewer written in C using SDL2.

## Features

- Reads and displays PPM P6 (binary) format images
- SDL2-based window rendering
- Pixel-by-pixel image rendering
- Interactive window with close event handling

## Prerequisites

- GCC compiler
- SDL2 library
- Make

### Installing SDL2

**Fedora/RHEL:**
```bash
sudo dnf install SDL2-devel
```

**Ubuntu/Debian:**
```bash
sudo apt-get install libsdl2-dev
```

**Arch Linux:**
```bash
sudo pacman -S sdl2
```

## Building

Simply run:
```bash
make
```

This will compile `image-viewer.c` and create the `image-viewer` executable.

## Usage

Place a PPM file named `fastfetch.ppm` in the same directory and run:
```bash
./image-viewer
```

The viewer will:
1. Read the PPM file
2. Parse the header (format, dimensions, max color value)
3. Display the image in an SDL2 window
4. Keep the window open until you close it

## PPM Format

The viewer expects PPM P6 (binary) format files with the following header structure:
```
P6
# Comment (optional)
width height
maxval
[binary RGB data]
```

## Project Structure

```
.
├── image-viewer.c      # Main source file
├── Makefile           # Build configuration
├── fastfetch.ppm      # Sample PPM image (not tracked)
└── README.md          # This file
```

## License

This is a simple educational project for learning SDL2 and image file formats.
