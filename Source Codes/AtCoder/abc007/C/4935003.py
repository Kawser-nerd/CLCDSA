from collections import deque

H, W = map(int, input().split())
sy, sx = map(lambda x: int(x)-1, input().split())
gy, gx = map(lambda x: int(x)-1, input().split())
maze = [input()for _ in range(H)]


def bfs(startx: int, starty: int) -> int:
    dxdy = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    queue = deque()
    queue.appendleft((startx, starty, 0))
    reached = set()
    while queue:
        d = queue.pop()
        if d[0] == gx and d[1] == gy:
            return d[2]
        for a in dxdy:
            x = d[0] + a[0]
            y = d[1] + a[1]
            if ((x, y) not in reached) and 0 <= x < W and 0 <= y < H and maze[y][x] != '#':
                queue.appendleft((x, y, d[2] + 1))
                reached.add((x, y))
    return -1


print(bfs(sx, sy))