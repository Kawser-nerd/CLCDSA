x1,y1,x2,y2 = map(int,input().split())

W,H = abs(x1-x2),abs(y1-y2)



flip_x = x1 > x2
flip_y = y1 > y2

xo = min(x1,x2)
yo = min(y1,y2)

N = int(input())

F = []

for i in range(N):
  x,y = map(int,input().split())
  x -= xo
  y -= yo
  if 0 <= x <= W and 0 <= y <= H:
    if flip_x:
      x = W-x
    if flip_y:
      y = H-y
    F.append((x,y))

N = len(F)

from math import pi
from bisect import bisect


#?????
L = (W+H)*100

if (W == 0 or H == 0) and F:
  L += pi*10-20
elif N > 0:
  # find LIS
  F.sort()
  F = [y for x,y in F]

  dp = [H+1]*len(F)

  for i,f in enumerate(F):
    dp[bisect(dp,f)] = f

  n = bisect(dp,H)

  L -= (20-pi*5)*n
  if n == min(W,H) + 1:
    L += pi*5

print(L)