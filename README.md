## ISDN3000e-Lab3

### X11 Configuration Issue
When building projects that use **Polyscope/GLFW**, you may encounter X11 error on Ubuntu/WSL. This happens because Polyscope depends on X11 for window creation, and the required development libraries are missing on your system.

### Solution
Run the following command in your **Ubuntu/WSL terminal** to install X11 development libraries:

```bash
sudo apt update
sudo apt install libx11-dev libxrandr-dev libxcursor-dev libxi-dev libxinerama-dev libgl1-mesa-dev libglu1-mesa-dev libglew-dev mesa-utils
```

If it's due to your GPU graphics configuration, please try to use CPU via set the following environment vairables in your project configuration:

```bash
LIBGL_ALWAYS_SOFTWARE=1;
GALLIUM_DRIVER=llvmpipe;
MESA_LOADER_DRIVER_OVERRIDE=llvmpipe
```


