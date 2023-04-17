#include <iostream>
#include <vector>
#define vii std::vector<int>
#define v_vii std::vector<vii>
using namespace std;
const int ROWS = 10;
const int COLS = 10;

void printGrid(const v_vii& grid)
{
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << (grid[i][j] == 1? 'W' : '.') << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void updateGenerations(v_vii& grid)
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


}

int main() {
    // spaceship glider
    v_vii grid(ROWS, vii(COLS,0));

    // initial
    grid[1][2] = 1;
    grid[2][3] = 1;
    grid[3][1] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;

    cout << "Initial" << endl;
    printGrid(grid);

    for (int i = 0; i < 10; ++i) {
        updateGenerations(grid);
        printGrid(grid);
    }



    return 0;
}
