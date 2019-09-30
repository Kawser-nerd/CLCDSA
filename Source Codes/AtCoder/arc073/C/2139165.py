# seishin.py
from heapq import heappush, heappop, heapify

N = int(input())
P = []
for i in range(N):
    x, y = map(int, input().split())
    P.append((x, y) if x < y else (y, x))

X = [x for x, y in P]
Y = [y for x, y in P]

MIN = min(X)
MAX = max(Y)

# R_min = MIN, B_max = MAX
res = (max(X) - MIN) * (MAX - min(Y))

# R_min = MIN, R_max = MAX
base = MAX - MIN
heapify(P)

# ??????????????(B_max - B_min)????
r = max(X)
while P:
    x, y = heappop(P)
    res = min(res, base * (r - x))
    if y != -1:
        # B?????x?R????????y?B????
        heappush(P, (y, -1))
        r = max(r, y)
    else:
        # (x, y) ?y???B_min???
        # => ????B_min??????
        break

print(res)