# -*- coding: utf-8 -*-
from collections import deque
h,w = map(int, input().split())
c = [input() for _ in range(h)]
check = [[0]*w for _ in range(h)]

for hi in range(h):
    for wi in range(w):
        if c[hi][wi]=="s":
            sh,sw = hi,wi


q = deque()
q.append((sh,sw))
for _ in range(3):
    wall = deque()
    while len(q)>0:
        hi,wi = q.popleft()

        for dh,dw in [[1,0],[0,1],[-1,0],[0,-1]]:
            if h>dh+hi>=0 and w>dw+wi>=0:
                if c[dh+hi][dw+wi]=="g":
                    print("YES")
                    exit()
                elif c[dh+hi][dw+wi]==".":
                    if check[dh+hi][dw+wi]==0:
                        check[dh+hi][dw+wi] = 1
                        q.append((dh+hi,dw+wi))
                else:
                    if check[dh+hi][dw+wi]==0:
                        check[dh+hi][dw+wi] = 1
                        wall.append((dh+hi,dw+wi))
    q = wall

print("NO")