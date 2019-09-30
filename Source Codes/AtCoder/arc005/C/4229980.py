# coding:utf-8

import sys
from collections import deque

INF = float('inf')
MOD = 10 ** 9 + 7
dy = (0, -1, 0, 1)
dx = (1, 0, -1, 0)

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


h, w = LI()
src = []
for i in range(h):
    C = SI()
    for j, c in enumerate(C):
        if c == 's':
            hs, ws = i, j
        if c == 'g':
            hg, wg = i, j
    src.append(C)

# 3: ???, 2: ??2??????, 1: ??1??????, 0: ????????????
visited = [[3] * w for _ in range(h)]
visited[hs][ws] = 0

# 01BFS
que = deque()
que.append((hs, ws))
while que:
    y, x = que.popleft()

    for k in range(4):
        yy, xx = y + dy[k], x + dx[k]
        if yy < 0 or yy >= h or xx < 0 or xx >= w:
            continue

        wall = src[yy][xx] == '#'
        dist = visited[y][x] + wall

        if visited[yy][xx] > dist:
            visited[yy][xx] = dist
            if visited[hg][wg] < 3:
                print('YES')
                exit()
            # ?????????????????
            if wall:
                que.append((yy, xx))
            else:
                que.appendleft((yy, xx))

print('NO')