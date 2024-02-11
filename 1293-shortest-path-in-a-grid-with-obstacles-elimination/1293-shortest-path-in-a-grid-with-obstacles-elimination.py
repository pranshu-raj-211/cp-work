class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        maze=grid
        m = len(maze)
        n = len(maze[0])
        moves_x = [0, 0, 1, -1]
        moves_y = [1, -1, 0, 0]

        steps = -1
        visited = {(0, 0, k)}
        frontier = []
        frontier.append((0,0, k))

        while frontier:
            steps += 1

            for _ in range(len(frontier)):
                x, y, walls_left = frontier.pop(0)

                if x == m - 1 and y == n - 1:
                    # goal test
                    return steps

                for i in range(4):
                    # try all moves
                    new_x = x + moves_x[i]
                    new_y = y + moves_y[i]
                    
                    if new_x < 0 or new_x == m or new_y < 0 or new_y == n:
                        # invalid move
                        continue
                    if maze[new_x][new_y] == 1 and walls_left == 0:
                        # can't break any more walls
                        continue
                    new_walls_left = walls_left - maze[new_x][new_y]
                    if (new_x, new_y, new_walls_left) in visited:
                        # already visited
                        continue
                    visited.add((new_x, new_y, new_walls_left))
                    frontier.append((new_x, new_y, new_walls_left))
        return -1
