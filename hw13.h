#ifndef __HW13_H__
#define __HW13_H__

// --- DO NOT CHANGE THIS FILE ---

// coordinate that stores x and y
typedef struct _coordinate {
    int x;
    int y;
} coordinate;

// node of linked list
typedef struct _node {
    int step;
    coordinate value;
    struct _node* next;
} node;

// linked list with head node
typedef struct _linkedList {
    node* head;
} linkedList;

char** maze_input(char* filename, int* num_row, int* num_col);
void print_maze(char** maze, int num_row, int num_col);
void maze_output(char** input, int num_row, int num_col);
void free_maze(char** maze, int num_row, int num_col);

#endif