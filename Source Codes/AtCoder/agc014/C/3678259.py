def solve():
    from collections import deque
    h, w, k = map(int, input().split())
    maze = [input() for _ in range(h)]
    visited = [[-1]*w for j in range(h)]
    for i in range(h):
        if 'S' in maze[i]:
            sy, sx = i, maze[i].index('S')
    queue = deque([[sy, sx]])
    visited[sy][sx] = 0
    r = 10**18
    while queue:
        y, x = queue.popleft()
        r = min(r, y, x, h-1-y, w-1-x)
        if visited[y][x] == k: continue
        for i, j in ([1, 0], [-1, 0], [0, 1], [0, -1]):
            new_y, new_x = y+i, x+j
            if new_y < 0 or new_y >= h: continue
            if new_x < 0 or new_x >= w: continue
            if maze[new_y][new_x] == '.' and visited[new_y][new_x] == -1:
                visited[new_y][new_x] = visited[y][x] + 1
                queue.append([new_y, new_x])
    print(1 -(-r // k))
if __name__ == '__main__':
    solve()