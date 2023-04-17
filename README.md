# Game Of Life in C++

Here's a high-level algorithm for implementing the Game of Life:

Initialize a grid:
 * Create a two-dimensional array representing the grid of cells. Each cell can be either alive (1) or dead (0), and you can randomly initialize the grid with some cells being alive and others being dead, or you can set an initial pattern according to your desired configuration.

### Update the grid: 
 * Iterate over each cell in the grid and determine its next state based on the current state of its eight neighboring cells. Conway's original rules for updating the state of a cell are as follows:

 * If a live cell has 2 or 3 live neighbors, it stays alive.
 * If a live cell has fewer than 2 live neighbors, it dies due to underpopulation.
 * If a live cell has more than 3 live neighbors, it dies due to overpopulation.
 * If a dead cell has exactly 3 live neighbors, it becomes alive due to reproduction.
### Apply the rules:
 * Update the state of each cell in the grid simultaneously based on the rules described above. You can either create a new grid to store the updated state or update the current grid in place, but be careful to avoid updating cells based on their partially-updated neighbors.

### Repeat: 
* Continue updating the grid based on the rules for a desired number of iterations or until a specific condition is met, such as reaching a stable state where no cells change their state anymore.

### Visualize: 
 * Optionally, you can visualize the state of the grid at each iteration to observe the evolution of the Game of Life simulation. You can represent live cells with a filled cell or a different color, and dead cells with an empty cell or a different color.

### End: 
 * Terminate the simulation when the desired number of iterations or condition is met, and optionally display the final state of the grid.

### Files 
 * SdlGeneralGamingPracticing (#include <SDL.h>) 
   * Create Window - Drawing - Animation(up down) - class rule 5 :D

 * There will be found glider pattern in game of life.
   * with sdl and string, easy to understand
   * ![Example Glider](/pics/glider.png)
   * Random Pattern but looking funny - u can change how u would like to 
   * ![Example Glider](/pics/game.png)
