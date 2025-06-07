<p align="center"> 
<img src="https://img.shields.io/badge/-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr))"> 
<img src="https://img.shields.io/badge/1337-000000?style=for-the-badge&logo=1337&logoColor=white)](https://1337.ma))">  
<img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)">
</p> 
<h1 align="center">🕹 so_long 🕹</h1> 


# so_long - 2D Game Development Project

## Project Overview

**so_long** is a fundamental 2D game development project in the 1337/42 School curriculum that introduces students to basic computer graphics programming, event handling, and game mechanics. The project challenges students to create a simple top-down 2D game using the MiniLibX graphics library, where a character must collect items and find an exit while navigating through a map.

The project serves as an introduction to:
- Window management and rendering
- Sprite handling and textures
- Basic game loops and event systems
- Map parsing and validation
- Memory management in graphics programming

## Technical Specifications

### Core Requirements
- **Language**: C
- **Graphics Library**: MiniLibX (MLX)
- **Map Format**: `.ber` files (custom format)
- **View**: Top-down 2D perspective
- **Movement**: 4-directional (W, A, S, D or arrow keys)

### Game Components
- **Player (P)**: The main character controlled by the user
- **Collectibles (C)**: Items that must be gathered before exiting
- **Exit (E)**: The goal point that becomes accessible after collecting all items
- **Walls (1)**: Impassable barriers that define the map boundaries
- **Empty Spaces (0)**: Walkable areas

### Map Requirements
- Rectangular shape with walls (1) forming the perimeter
- Exactly one player starting position (P)
- Exactly one exit point (E)
- At least one collectible item (C)
- Valid path must exist from player to all collectibles and the exit

## Project Roadmap

### Phase 1: Foundation Setup
**Objective**: Establish the basic project structure and understand MLX

**Key Tasks**:
- Set up project directory structure with proper Makefile
- Initialize MLX library and create basic window
- Implement basic window management (creation, destruction, events)
- Handle ESC key to close window and red cross button
- Create basic error handling framework

**Learning Focus**:
- MLX initialization and basic functions
- Event loop understanding
- Memory allocation patterns for graphics

### Phase 2: Map System Development
**Objective**: Implement robust map parsing and validation

**Key Tasks**:
- Create map file parser for `.ber` format
- Implement comprehensive map validation
  - Check rectangular shape
  - Validate wall boundaries
  - Count and verify game elements (P, E, C)
  - Ensure single player and exit
- Develop flood fill algorithm for path validation
- Create error reporting system for invalid maps

**Learning Focus**:
- File I/O operations
- String manipulation and parsing
- Algorithm implementation (flood fill)
- Data structure design for map representation

### Phase 3: Graphics and Sprite Management
**Objective**: Load and manage game sprites efficiently

**Key Tasks**:
- Load XPM image files for all game elements
- Create sprite structure for easy management
- Implement texture-to-window rendering system
- Design scalable sprite loading system
- Handle different sprite sizes and positioning

**Learning Focus**:
- Image file handling
- Texture mapping concepts
- Graphics coordinate systems
- Resource management

### Phase 4: Game Logic Implementation
**Objective**: Create core gameplay mechanics

**Key Tasks**:
- Implement player movement system
- Add collision detection with walls
- Create collectible gathering mechanism
- Track game state (collected items, move counter)
- Implement win condition checking
- Add move counter display

**Learning Focus**:
- Game state management
- Collision detection algorithms
- User input processing
- Game loop architecture

### Phase 5: Advanced Features and Polish
**Objective**: Enhance gameplay and add finishing touches

**Key Tasks**:
- Implement smooth sprite animations (bonus)
- Add enemy patrol systems with AI (bonus)
- Create multiple level support
- Optimize rendering performance
- Add comprehensive error handling
- Implement proper cleanup and exit procedures

**Learning Focus**:
- Animation techniques
- Basic AI pathfinding
- Performance optimization
- Code organization and modularity

## Technical Challenges

### Map Validation Complexity
The project requires sophisticated validation to ensure maps are playable. This includes checking for enclosed areas, unreachable collectibles, and proper wall boundaries.

### Memory Management
Graphics programming demands careful memory management, particularly with texture loading and MLX resource handling to prevent leaks.

### Event Handling
Implementing smooth and responsive controls while maintaining a stable game loop requires understanding of event-driven programming.

### Pathfinding Algorithms
The flood fill algorithm for path validation introduces students to fundamental pathfinding concepts used throughout game development.


## Learning Outcomes

Upon completion, students will have gained experience in:
- Low-level graphics programming
- Game development fundamentals
- Algorithm implementation and optimization
- Resource management in C
- Event-driven programming patterns
- File parsing and validation techniques
- Debugging graphics applications
