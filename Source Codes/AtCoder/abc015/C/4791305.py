from itertools import product
from functools import reduce
from operator import xor

N, K =map(int, input().split())
T = [[int(_) for _ in input().split()] for _ in range(N)]
flag = False

for i in product(*T):
    if reduce(xor, i) == 0:
        flag = True
        break

print("Found" if flag else "Nothing")