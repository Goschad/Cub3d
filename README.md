# cub3D

A 3D raycasting engine inspired by Wolfenstein 3D, built from scratch in C as part of the 42 school curriculum. The project renders a first-person view of a maze defined in a `.cub` map file using the DDA raycasting algorithm.

## Features

- First-person 3D rendering via raycasting (DDA algorithm)
- Textured walls with directional textures (North, South, East, West)
- Configurable floor and ceiling colors
- Player movement — walk, strafe, rotate, run
- Mouse camera control
- Doors — open and auto-close
- Weapons and emote animations
- 2D minimap overlay
- Full `.cub` map file parsing and validation

## Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` `→` | Rotate camera |
| `Left Shift` | Run |
| `R` | Open door |
| `F` | Emote |
| `Mouse` | Camera rotation |
| `ESC` | Quit |

## Project Structure

```
cub3D/
├── src/
│   ├── main.c                    # Entry point
│   ├── init.c                    # Initialization
│   ├── parse_map.c               # .cub file parsing
│   ├── check.c / check_2.c       # Map validation
│   ├── raycastig.c               # Main raycaster loop
│   ├── horizontal_ray.c          # Horizontal ray intersections
│   ├── vertical_ray.c            # Vertical ray intersections
│   ├── math.c                    # Drawing and math utils
│   ├── player.c                  # Player rendering
│   ├── move_utils.c              # Movement and rotation
│   ├── key.c                     # Key hooks
│   ├── mouse.c                   # Mouse control
│   ├── door.c                    # Door logic
│   ├── weapon.c                  # Weapon rendering
│   ├── emote.c                   # Emote animation
│   ├── utils_texture.c           # Texture loading and drawing
│   ├── utils_texture_check*.c    # Texture validation
│   ├── utils_map_check*.c        # Map boundary validation (flood fill)
│   ├── character_utils.c         # Player spawn point
│   ├── hide_map.c                # Map sanitization
│   ├── true_map.c                # Map copy utilities
│   ├── lib_utils.c               # ft_strdup, ft_strcmp, ft_strjoin...
│   ├── another_utils.c           # ft_strrlen, delete_all_newline...
│   ├── ft_split.c                # String split
│   ├── ft_atoi.c / ft_itoa.c     # Number conversions
│   ├── error.c                   # Error handling
│   └── quit.c                    # Clean exit and free
├── get_next_line/                # GNL implementation
├── MLX42/                        # Graphics library (submodule)
├── map/                          # Example .cub map files
├── img_t/                        # Texture images
├── wea_t/                        # Weapon textures
├── fuc_t/                        # Emote textures
├── cub3d.h                       # Main header
└── Makefile
```

## Map Format (.cub)

```
NO ./img_t/wall_north.png
SO ./img_t/wall_south.png
WE ./img_t/wall_west.png
EA ./img_t/wall_east.png

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

**Map tiles:**
- `1` — wall
- `0` — empty space
- `N` `S` `E` `W` — player spawn + initial direction
- `D` — door
- Space — void (outside the map)

**Validation rules:**
- Map must be surrounded by walls on all sides
- Exactly one player spawn point
- Texture paths must be valid
- Colors must be in `R,G,B` format (0–255)

## Setup

### Prerequisites

- **macOS** with [Homebrew](https://brew.sh/)
- `gcc`, `make`
- `glfw` — `brew install glfw`
- MLX42 must be compiled (included as a static library)

### Build

```bash
git clone https://github.com/Goschad/Cub3d
cd Cub3d
make
```

### Run

```bash
./cub3D map/your_map.cub
```

### Clean

```bash
make clean    # removes object files
make fclean   # removes object files + binary
make re       # fclean + build
```

## Technical Details

### Raycasting

For each column of the screen, a ray is cast from the player's position. The engine computes intersections with horizontal and vertical grid lines separately (DDA algorithm), then picks the closest hit to determine wall distance. The wall slice height is computed from the inverse of the distance to correct the fisheye effect.

### Textures

Each wall face has a directional texture (N/S/E/W). The exact column within the texture is determined by the hit position on the wall. Texture rows are sampled with a step proportional to the wall slice height.

### Map Validation

A flood-fill algorithm verifies that the map is fully enclosed — any accessible tile must be reachable only through walls, never through the void.

## Authors

- **mbouaza** — [@Goschad](https://github.com/Goschad)
- **gcherqui** — [@tbagskk](https://github.com/tbagskk)