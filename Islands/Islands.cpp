#include <vector>
#include <assert.h>
#include <iostream>

/*
 * To analyze satellite images, a geospatial company studies maps of remote ocean regions.
 * Each map is represented as a grid where land and water are identified.
 *
 * Your task is to determine how many separate islands are present on a given map.
 * The map is represented as a 2D grid of characters :
 *    - '1' represents land
 *    - '0' represents water
 *
 * An island is defined as a group of connected land cells.
 * Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
 * The grid is surrounded by water.
 * 
 * Implement the function count_islands which returns the total number of islands present in the map.
 */

void  ExploreCell(std::vector<std::vector<char>>& grid, int x, int y)
{
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size()) return;
    if (grid[x][y] == '0') return;

    grid[x][y] = '0';


    ExploreCell(grid, x + 1, y);
    ExploreCell(grid, x - 1, y);
    ExploreCell(grid, x, y + 1);
    ExploreCell(grid, x, y - 1);

}

int count_islands(std::vector<std::vector<char>>& grid)
{
    int count = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                ExploreCell(grid, i, j);
            }
        }
    }

    return count;
}



int main()
{
    {
        std::vector<std::vector<char>> grid = {
            {'1','1','0','0'},
            {'1','1','0','0'},
            {'1','0','1','0'},
            {'1','0','0','1'}
        };
        assert(count_islands(grid) == 3);
    }

    return 0;
}