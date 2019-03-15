# Maze-solving-algorithm

Solving Mouse in a maze problem using 2 stacks:
At its current position mouse checks number of available paths
-if there is only one path it traverses the maze and pushes its position on top of the Visited stack
- if more than 1 path is available, a decision token is pushed in visited stack, then the mouse traverses the first available path (left for example) and pushes every other possible path in the Backtrack stack
- if no exit is found the mouse returns to decision token (pops every node in Visited stack until decision token), then pops the first option in the Backtrack stack and tries a new path until an exit is found
