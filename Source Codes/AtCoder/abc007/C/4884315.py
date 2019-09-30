from collections import deque

def bfs(maze, visited, sy, sx, gy, gx):
    queue = deque([[sy, sx]])
    visited[sy][sx] = 0
    while queue:
        y, x = queue.popleft()
        if [y, x] == [gy, gx]:
            return visited[y][x]
        for j, k in ([1, 0], [-1, 0], [0, 1], [0, -1]):
            new_y, new_x = y+j, x+k
            if maze[new_y][new_x] == "." and \
                visited[new_y][new_x] == -1:
                visited[new_y][new_x] = visited[y][x] + 1
                queue.append([new_y, new_x])

if __name__ == "__main__":
    R, C = map(int, input().split())
    sy, sx = map(int, input().split())
    gy, gx = map(int, input().split())
    sy, sx, gy, gx = sy-1, sx-1, gy-1, gx-1

    maze = [input() for i in range(R)]
    visited = [[-1]*C for j in range(R)]
    print(bfs(maze, visited, sy, sx, gy, gx))