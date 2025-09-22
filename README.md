# Maze (ECE_264F2025_HW13)
## Description

You need to find the shortest path from the start to the end, one step at a time. By finishing this assignment, you can learn how to solve a classic maze game in C.

## Input
The input text file will contain a _rectangular_ maze map with components below. 

### Input Characters

- First line: two numbers contains `number_of_rows,number_of_cols`, and separated by a ',' without space. 

- Component `#`: means Wall. You cannot walk on or go cross the wall.

- Component `P`: means Path. You can walk on path freely. You can go all four directions.

- Component `S`: means Start. You start from this location.

- Component `E`: means End. You end at this location.

### Input Format
- There will be only one Start, and only one End.

- The Maze will have walls surrounding the center map.

- _There are some maze maps cannot be solved._

- The shortest path will be unique, so the output answer will be unique.

- The Start will be at the first column, and will not be at the first or last row. 

- The End will be at the last column, and will not be at the first or last row. 

## Coordinate Format

Suppose we have `a` rows and `b` columns. We say: 
- _top left_ character coordinate to be `0,0`.
- _right bottom_ character coordinate to be `b-1,a-1`.

For example, we have: (the characters are not for this maze, only for coordinate demo)

```
ABCD    A: 0,0 | B: 1,0 | C: 2,0 | D: 3,0
EFGH    E: 0,1 | F: 1,1 | G: 2,1 | H: 3,1
IJKL    I: 0,2 | J: 1,2 | K: 2,2 | L: 3,2
```




## Output

### Example

#### Example input

```
10,10
##########
SPPPPPPPP#
#P#P###PP#
#PP#PP#PP#
#P###PPPP#
#P#PPPPP##
#P##P##P##
#P##P#####
#PPPPPPPPE
##########
```
It contains two correct paths from Start to End. 

We choose the one with 16 steps, over the one with 22 steps, because 16 steps is faster. 

#### Example output

The output to the maze above:
```
16
0,1
1,1
1,2
1,3
1,4
1,5
1,6
1,7
1,8
2,8
3,8
4,8
5,8
6,8
7,8
8,8
9,8
```

### Explanation

- You don't need to write output to a file, you can directly print to console.
- First line: you should output the total number of steps n, from Start to End.
- Second line: you should output the Coordinate of the Start location.
- Following lines: you should output the Coordinate of every step from the Start to the End. (Start and End location excluded, and one step at a time)
- Last line: you should output the Coordinate of the End location.
- There is no extra empty line. 

### No Solution

If there is no solution to the maze, you need to print:
```
No Solution
```
Just one line with no extra space at the end. 

## What to Do

Do not change `hw13.h` and `main.c`.

Do edit `hw13.c`.

In `hw13.h`, `coordinate`, `node`, and `linkedList` data types are provided. You can use linkedList to make a queue. The `step` in `node` will help you in recording the steps. If you don't want to use it, just set it to random number. 

In `hw13.c`, helper functions`free_maze`, `print_maze`, `construct_node`, `get_start`, and `get_end` are provided. You can choose to use them, or create your own helper functions. 

- You _need_ to finish `maze_input` and `maze_output`, as they will be implemented in the main function.

- You _can_ choose to fill in `enqueue` and `dequeue`, as they can be useful, or have all helper functions of your own.

- You _can_ have your customized structure in `hw13.c`, as long as they work. 

In `maze_input` function, you _need_ to read maze into a 2D char array, with number of rows and columns. You _can_ uncomment `print_maze` in main to check maze. 

In `maze_output` function, you _need_ to print expected output.

## Maybe Useful Concepts (Not Detailed)

These ideas may help you with doing the Homework. You don't have to use this.

### Breath First Search (BFS)

The data structure used to implement this method is called Queue. Queue uses First In First Out (FIFO) to keep track of next position to visit. A few nodes come in, and they will get out in the order of they come in. 

```
Queue Visialize...

--- First Move ---
Queue Action: enqueue(node1)
Queue: 

node1

Return: N/A

--- Second Move ---
Queue Action: enqueue(node2)
Queue:

node1
node2

Return: N/A

--- Third Move ---
Queue Action: dequeue()
Queue: 

node2
node3

Return: node1

--- Forth Move ---
Queue Action: enqueue(node4)
Queue: 

node2
node3
node4

Return: N/A

--- Fifth Move ---
Queue Action: dequeue()
Queue: 

node3
node4

Return: node2
```

Usually, we just put in all the coordinates surrounding the current coordinate into queue. Then, we get one coordinate out from queue, and we move one step to it's surrounding. Do same thing for all elements in the queue. 

Finally, The End node will be detected.

```
This is the pseudo-code for BFS...

bfs():
    create a queue Queue
    create a visited list Visited
    create a backtrack Type Map // your turn to design

    enqueue(start_position)

    while Queue not empty:
        current_node = dequeue(Queue)
        ...
        ...
        ...
        for each neighbour:
            if not in Visited and is path:
                enqueue(neighbour)
                add neighbour in Visited
                update Map
    ...
    ...
    ...
```

### Depth First Search (DFS)

The difference of DFS to BFS is that DFS uses another data structure, called Stack. Stack uses Last In First Out (LIFO) to keep track of next position to visit. A few nodes are put in, the last one go in will come out first.

Recursion has inherent DFS behaviour.
```
This is the pseudo-code for DFS...

dfs(node):
    if node is visited:
        return
    
    if node is End:
        update Map
        return
    
    for each neighbour:
        dfs(neighbour)
```

### Back Tracking

You can create a linked list or a 2D array to store the store the path you go through. After arrive at the End, you can print out the path from the Start. 

Usually, we have pair of "Coordinate From" and "Coordinate To" stored as HashMap or Dictionary in. When we are at the End, we just search for "Coordinate From" for End, and recursively backwards. 

We don't have simple structure to do that in C, however. Therefore, we can have a 2D array similar to the one we save maze map, we can record the data on each node. 
