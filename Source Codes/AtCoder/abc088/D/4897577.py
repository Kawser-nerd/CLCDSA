from collections import deque, Counter
from functools import reduce


H, W = map(int, input().split(" "))
area_info = [input() for _ in range(H)]

is_visit = [[False for _ in range(W)] for _ in range(H)]

next_search = deque([[0, 0, 0], ])


def get_shortest_step():
    shortest_step = -1
    while len(next_search) > 0:
        nowx, nowy, now_step = next_search.pop()
        if is_visit[nowx][nowy]:
            continue
        is_visit[nowx][nowy] = True

        for stepx, stepy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            nextx = nowx + stepx
            nexty = nowy + stepy
            if nextx == H-1 and nexty == W-1:
                shortest_step = now_step + 1
                return shortest_step
            if 0 <= nextx < H and 0 <= nexty < W:
                if is_visit[nextx][nexty] or area_info[nextx][nexty] == "#":
                    continue
                next_search.appendleft([nextx, nexty, now_step+1])
    return shortest_step


shortest_step = get_shortest_step()
c = Counter("".join(area_info))
if shortest_step == -1:
    print("-1")
else:
    print(c['.'] - shortest_step - 1)