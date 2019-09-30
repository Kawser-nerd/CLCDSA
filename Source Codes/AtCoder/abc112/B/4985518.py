# coding: utf-8
import sys

ans = sys.maxsize

N, T = map(int, input().split())
for i in range(0, N):
    c, t = map(int, input().split())
    if t <= T:
        ans = min(ans, c)

if ans == sys.maxsize:
    print("TLE")
else:
    print(ans)