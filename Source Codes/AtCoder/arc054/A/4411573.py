# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
L, X, Y, S, D = map(int, input().split())

if S >= D:
    distL = S-D
    distR = L-distL
    velR = X+Y
    velL = Y-X
    if velL <= 0:
        ans = distR/velR
    else:
        ans = min(distR/velR, distL/velL)
else:
    distR = D-S
    distL = L-distR
    velR = X+Y
    velL = Y-X
    if velL <= 0:
        ans = distR/velR
    else:
        ans = min(distR/velR, distL/velL)
print(ans)