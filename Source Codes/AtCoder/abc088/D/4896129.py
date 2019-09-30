# -*- coding: utf-8 -*-

from queue import Queue

h,w = map(int,input().split())
black, white = 0,0
s = [[0] * w for _ in range(h)]
for i in range(h):
    s[i] = list(input())
    for j in range(w):
        if s[i][j] == ".":
            white += 1
        else:
            black += 1

def bfs():
    global ans,checked
    while not que.empty():
        xy = que.get()
        if xy[0] == w - 1 and xy[1] == h - 1:
            ans = checked[xy[1]][xy[0]]
            return
        for i in range(-1,2):
            for j in range(-1,2):
                if i == j or i == -j:
                    continue
                if 0 <= xy[0] + i < w and 0 <= xy[1] + j < h:
                    if checked[xy[1] + j][xy[0] + i] == -1 and s[xy[1] + j][xy[0] + i] == ".":
                        checked[xy[1] + j][xy[0] + i] = checked[xy[1]][xy[0]] + 1
                        que.put([xy[0] + i,xy[1] + j])

que = Queue()
ans = -1
checked = [[-1] * w for _ in range(h)]
checked[0][0] = 0
que.put([0,0])

bfs()
if ans != -1:
    print(white - ans - 1)
else:
    print(-1)