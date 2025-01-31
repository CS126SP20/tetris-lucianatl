# Tetris++


A tetris game written in C++

[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)
![](assets/tetris_screenshot.png)
## Installation

You will need to install [Cinder](https://libcinder.org/download).

You will also need to install the external libraries [PretzelGui](https://github.com/cwhitney/PretzelGui)
and [Catch2](https://github.com/catchorg/Catch2).


## How To Play

Press Enter/Return on the starting screen and and play with the following controls

| Key      | Action                                             |
|----------|----------------------------------------------------|
| `↑` , `k` , `w` | Rotate falling piece                        |
| `→` , `l` , `d` | Move falling piece to the right		        |
| `←` , `h` , `a` | Move falling piece to the left              |
| `↓` , `s` , `j` | Move falling piece down                     |
| `p`             | pause                                       |

Filling a row/line will clear it. The scoring system for the game follows the original BPS scoring system. 
Points and level will be displayed in the upper right hand corner.

| Line Clear | Points                   |
|------------|--------------------------|
| 1 (single) | 40                       |
| 2 (double) | 100					    |
| 3 (triple) | 300                      |
| 4 (tetris) | 1200                     |

After an 10 lines are cleared, the level and falling piece speed increases.

Any piece placed above the board will end the game.

## Credits

[Tetris tutorial in C++ platform](http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/)

[CS126SP20 Snake Game App](https://github.com/CS126SP20/snake-ssuni2)

**Author**: Luciana Toledo-López - [`lucianat@illinois.edu`](mailto:lucianat@illinois.edu)
