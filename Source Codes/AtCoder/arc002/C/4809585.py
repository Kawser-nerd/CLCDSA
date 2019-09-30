from itertools import product
import re
def inpl(): return list(map(int, input().split()))
N = int(input())
C = input()
ans = 2000
for X in product("ABXY", repeat=4):
    L = "".join(X[:2])
    R = "".join(X[2:])
    ans = min(ans, len(C.replace(L, "L").replace(R, "R")))
print(ans)