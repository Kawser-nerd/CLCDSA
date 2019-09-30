# coding:utf-8

import sys
import heapq

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


def dijkstra(start: tuple, goal: tuple, size_h: int, size_w: int, graph: list, weight: int) -> int:
    D = [(0, 1), (-1, 0), (0, -1), (1, 0)]
    costs = [[INF] * size_w for _ in range(size_h)]
    y, x = start
    gy, gx = goal
    costs[y][x] = 0
    visited = set()
    hp = []
    heapq.heappush(hp, (0, y, x))
    while hp:
        c, y, x = heapq.heappop(hp)
        if (y, x) in visited:
            continue
        for dy, dx in D:
            ny, nx = y + dy, x + dx
            if ny < 0 or ny >= size_h or nx < 0 or nx >= size_w:
                continue
            nc = weight if graph[ny][nx] == '#' else 1
            if c + nc >= costs[ny][nx] :
                continue
            costs[ny][nx] = c + nc
            heapq.heappush(hp, (costs[ny][nx], ny, nx))
        visited.add((y, x))
        if (gy, gx) in visited:
            break

    return costs[gy][gx]


h, w, t = LI()
B = []
for i in range(h):
    s = SI()
    for j in range(w):
        c = s[j]
        if c == 'S':
            start = (i, j)
        if c == 'G':
            goal = (i, j)
    B.append(list(s))

left, right = 0, t
while left + 1 < right:
    mid = (left + right) // 2
    if dijkstra(start, goal, h, w, B, mid) > t:
        right = mid
    else:
        left = mid

ans = (left + right) // 2
print(ans)