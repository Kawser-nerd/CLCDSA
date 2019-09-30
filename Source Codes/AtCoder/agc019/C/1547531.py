# C
from bisect import bisect
import math
x1, y1, x2, y2 = map(int, input().split())
N = int(input())

xL = min(x1, x2)
xR = max(x1, x2)
yL = min(y1, y2)
yR = max(y1, y2)

xyl = []

if x1 < x2 and y1 > y2:
    direction = 'rightdown'
elif x1 > x2 and y1 < y2:
    direction = 'rightdown'
else:
    direction = 'rightup'
    
    
# sort
if direction == 'rightup':
    for _ in range(N):
        x, y = map(int, input().split())
        if xL <= x and x <= xR and yL <= y and y <= yR:
            xyl.append((x, y-yL))
else:
    for _ in range(N):
        x, y = map(int, input().split())
        if xL <= x and x <= xR and yL <= y and y <= yR:
            xyl.append((x, yR-y))

ind = len(xyl)
xyl.sort()

# calculate
dp = [yR-yL+1]*(ind)
for i in range(ind):
    _, y = xyl[i]
    dp[bisect(dp,y)] = y
count_ = bisect(dp,yR-yL)

diff = 5*math.pi - 20
diff2 = 10*math.pi - 20
if count_ == min((xR-xL), (yR-yL)) + 1:
    print(100*((xR-xL) + (yR-yL)) + (count_-1)*diff + diff2)
else:
    print(100*((xR-xL) + (yR-yL)) + count_*diff)