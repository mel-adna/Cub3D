# Cub3D Project

**Authors:**  
- Mohamed El Adnani — Raycasting & Rendering  
- Said Zemmouri — Parsing

---

## Overview

Cub3D is a simple 3D game engine inspired by classic raycasting games like Wolfenstein 3D. It simulates a 3D environment using a 2D map by casting rays to detect walls and rendering the scene from a first-person perspective.

---

## Features

- Raycasting engine for wall detection and distance calculation  
- Real-time 3D rendering with textures applied to walls  
- Map parsing and validation (done by Said Zemmouri)  
- Player movement and collision detection  
- Mouse support for camera rotation  
- Texture mapping for enhanced visuals  

---

## My Contribution

I, **Mohamed El Adnani**, was responsible for the **raycasting and rendering** parts:

- Implemented the raycasting algorithm  
- Rendered the 3D scene frame by frame using MiniLibX  
- Loaded and applied textures to walls  
- Integrated mouse support for camera control  
- Optimized rendering for smooth gameplay

My partner, **Said Zemmouri**, handled **map parsing**.

---

## How to Run

1. Clone the repo  
2. Compile the project using `make`  
3. Run the executable with a map file as argument

```bash
make
./cub3d maps/your_map.cub
