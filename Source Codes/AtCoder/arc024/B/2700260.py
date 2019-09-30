from copy import deepcopy
from math import ceil
N = int(input())
CC = [int(input()) for i in range(N)]
C = deepcopy(CC)
for c in CC:
    C.append(c)
if len(set(C)) == 1:
    print(-1)
    exit()

X = 1
now = C[0]
tmp = 1
for c in C[1:]:
    if c == now:
        tmp += 1
    else:
        X = max(X, tmp)
        now = c
        tmp = 1
print(ceil(X / 2))