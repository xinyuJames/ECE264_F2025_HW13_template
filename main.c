#include <stdio.h>
#include <stdlib.h>
#include "hw13.h"

/// --- DO NOT CHANGE THIS FILE ---

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Invalid Input\n");
        return 1;
    }

    int num_row, num_col;
    char** maze = maze_input(argv[1], &num_row, &num_col);
    //print_maze(maze, num_row, num_col);
    maze_output(maze, num_row, num_col);
    free_maze(maze, num_row, num_col);

    return 0;
}