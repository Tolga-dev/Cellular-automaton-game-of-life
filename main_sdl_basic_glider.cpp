#include <iostream>
#include <utility>
#include <vector>
#include <SDL2/SDL.h>

#define vii std::vector<int>
#define v_vii std::vector<vii>
using namespace std;
const int ROWS = 50;
const int COLS = 50;
const int CELL_SIZE = 10;

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); cout << msg << " SDL failed! " << endl; \
        } while (0)
#define handle_success(msg) \
    do { cout << msg << " Working! " << endl; \
        } while (0)


class Glider
{
public:
    Glider(int height_, int width_,v_vii& grid_) :
    height(height_), width(width_), grid(grid_)
    {

        if (SDL_Init(SDL_INIT_VIDEO) < 0)
            handle_error(SDL_GetError());
        else
            handle_success("Initialization");

        window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   COLS * CELL_SIZE, ROWS * CELL_SIZE, SDL_WINDOW_SHOWN);

        if (window == nullptr) {
            SDL_Quit();
        }
        else
            handle_success("Windows");

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr) {
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
        else
            handle_success("Renderer");

    }
    ~Glider()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    void Print()
    {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                cout << (grid[i][j] == 1? 'W' : '.') << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void UpdateGeneration()
    {
        v_vii next_generation = grid;

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {

                int lives = 0; // count every pixel in row and col print the new generation

                for (int ni = i-1; ni <= i+1 ; ++ni) {
                    for (int nj = j-1; nj <= j + 1  ; ++nj) {
                        if(ni > 0 && nj>0 && ni<ROWS && nj <COLS && !(ni == i && nj == j))
                        {
                            lives += grid[ni][nj];
                        }
                    }
                }

                if(grid[i][j] == 1)
                {
                    if(lives < 2 || lives > 3) // over population and less population
                        next_generation[i][j] = 0;
                }
                else
                if(lives == 3)
                    next_generation[i][j] = 1;

            }
        }
        grid = next_generation;

    };
    void DrawCells()
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set draw color to white
        SDL_RenderClear(renderer); // Clear the renderer

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set draw color to black
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1) {
                    SDL_Rect rect = {j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE};
                    SDL_RenderFillRect(renderer, &rect); // Draw a filled rectangle for live cell
                }
            }
        }

        SDL_RenderPresent(renderer); // Update the screen
    }

private:
    v_vii &grid;
    v_vii next_grid;
    int pix_life = 0;
    int height;
    int width;
    SDL_Renderer *renderer = nullptr;      // Pointer for the renderer
    SDL_Window *window = nullptr;      // Pointer for the window
};


int main() {
    // spaceship glider

    std::vector<std::vector<int>> grid(ROWS, std::vector<int>(COLS, 0));
    Glider glider(200,400,grid);
    SDL_Event event;


 // glider
    grid[20][20] = 1;
    grid[21][20] = 1;
    grid[22][20] = 1;
    grid[22][21] = 1;
    grid[21][22] = 1;

    // idont know what the f* is that lol
/*
    grid[25][24] = 1;
    grid[27][24] = 1;
    grid[25][25] = 1;
    grid[26][25] = 1;
    grid[25][26] = 1;
*/


    glider.Print();
    bool QUIT = false;

    while(!QUIT)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                QUIT = true;
            }
        }
        glider.UpdateGeneration();
        glider.DrawCells();

        SDL_Delay(100);
    }

    glider.Print();


    return 0;
}
