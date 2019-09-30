# coding: utf-8
import sys

diff = sys.maxsize
ans = ""

N = int(input())
T, A = map(int, input().split())
H = list(map(int, input().split()))

for i in range(0, N):
    t = T - H[i] * .006
    d = abs(A - t)
    if diff > d:
        ans = i + 1
        diff = d

print(ans)