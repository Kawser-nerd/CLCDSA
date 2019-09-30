# -*- coding: utf-8 -*-

from queue import Queue

h,w = map(int,input().split())
sy,sx = map(int,input().split())
sy -= 1
sx -= 1
gy,gx = map(int,input().split())
gy -= 1
gx -= 1
map = [[0] for _ in range(h)]
for i in range(h):
    map[i] = list(input())

que = Queue()
que.put([sx,sy])
checked = [[-1] * w for _ in range(h)]
checked[sy][sx] = 0
ans = 0

def bfs():
    global que,checked,ans
    while not que.empty():
        xy = que.get()
        if xy[0] == gx and xy[1] == gy:
            ans = checked[xy[1]][xy[0]]
        for i in range(-1,2):
            for j in range(-1,2):
                if i == j or i == -j:
                    continue
                if 0 <= xy[0] + i < w and 0 <= xy[1] + j < h:
                    if map[xy[1]+j][xy[0]+i] == "." and checked[xy[1]+j][xy[0]+i] == -1:
                        checked[xy[1]+j][xy[0]+i] = checked[xy[1]][xy[0]] + 1
                        que.put([xy[0]+i,xy[1]+j])

bfs()
print(ans)