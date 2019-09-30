from collections import deque
import math
H, W, K = map(int, input().split())
m = []
startx, starty = (0, 0)
for i in range(0,H):
    a=[c for c in input()]
    if "S" in a:
        startx, starty = (a.index("S"), i)
    m.append(a)

dq = deque()
dq.append([startx, starty, K])
dist = 9999999999999999999
hist = [[False]*W for i in range(H)]
hist[starty][startx] = True

while len(dq) > 0:
    x, y, turn = dq.popleft()

    dist = min(dist, x, y, W-1-x, H-1-y)
    if dist == 0:
        break
    if turn > 0:
        turn -= 1
        #move
        for dx, dy in ((0,-1), (1,0), (0,1), (-1,0)):
            newx, newy = (x+dx, y+dy)
            if m[newy][newx] == "." and not hist[newy][newx]:
                dq.append([newx, newy, turn])
                hist[newy][newx] = True

print(1+math.ceil(dist/K))