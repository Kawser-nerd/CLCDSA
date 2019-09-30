from itertools import accumulate
from operator import add
 
N, K = map(int, input().split())
K2 = 2 * K
 
# Gss[i][j]: ??????????????????(i,j)?????????????
Gss = [[0] * K2 for i in range(K2)]
 
for i in range(N):
    x, y, c = input().split()
    x, y = int(x), int(y)
 
    # ????0<=x<2K, 0<=y<K, 'B'??????
    if c == 'W':
        x -= K
    x, y = x % K2, y % K2
 
    if y >= K:
        x, y = (x - K) % K2, y - K
 
    # ????????????????????????????+1??
    # ??????????
    Gss[x][y] += 1
    Gss[x][y - K] += -1
    if x != K:
        Gss[x - K][y - K] += 1
        Gss[x - K][y] += -1
    if x > K:
        Gss[0][y] += 1
        Gss[0][y - K] += -1
 
# ??????
Gss = [accumulate(Gs) for Gs in Gss]
Gss = [accumulate(Gs) for Gs in zip(*Gss)]
Gss = list(map(list, zip(*Gss))) # ??
 
# ?K<=y<2K???????0<=y<K????????
Gss = [map(add, Gss[i][:K], Gss[i - K][K:]) for i in range(K2)]
 
# Gss???????
print(max(map(max, Gss)))