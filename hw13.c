#include <stdio.h>
#include <stdlib.h>
#include "hw13.h"

// --- PROVIDED FUNCTION START --- (you can change)
coordinate get_start(char** maze, int num_row); // get coordinate for start
coordinate get_end(char** maze, int num_col); // get coordinate for end
node* construct_node(coordinate c); // step=0; (x,y)=(0,0); next=NULL

coordinate get_start(char** maze, int num_row)
{
    int count = 0;
    coordinate start;
    for (int i = 0; i < num_row; i++)
    {
        if (maze[i][0] == 'S')
        {
            start.x = 0;
            start.y = i;
            break;
        }
    }
    return start;
}

coordinate get_end(char** maze, int num_col)
{
    coordinate end;
    for (int i = 0; i < num_col; i++)
    {
        if (maze[i][num_col-1] == 'E')
        {
            end.x = num_col-1;
            end.y = i;
            break;
        }
    }
    return end;
}

node* construct_node(coordinate c)
{
    node* rtn_node = malloc(sizeof(node));
    rtn_node->step = 0;
    rtn_node->value = c;
    rtn_node->next = NULL;

    return rtn_node;
}

void print_maze(char** maze, int num_row, int num_col) // print maze to check if parsing if correct
{
    for (int i = 0; i < num_row; i++) // print row
    {
        for (int j = 0; j <num_col; j++) // print col
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}
// --- PROVIDED FUNCTION END --- (you can change)


// --- EDIT START HERE ---
void enqueue(coordinate c, linkedList* list, int pre_step);
node dequeue(linkedList* list);

// read maze and return stored value
char** maze_input(char* filename, int* num_row, int* num_col)
{
    return NULL;
}

// print expected output
void maze_output(char** maze, int num_row, int num_col)
{
    return;
}

// put new element in the queue
void enqueue(coordinate c, linkedList* list, int pre_step)
{
    return;
}

// get an element out of queue
node dequeue(linkedList* list)
{
    return;
}

void free_maze(char** maze, int num_row, int num_col) // free maze that stored in 2D char array
{
    return;
}



