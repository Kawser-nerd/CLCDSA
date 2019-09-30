# encoding: utf-8
import sys
input = sys.stdin.readline
inf = 10 ** 18

N, K = map(int, input().split())
T = [list(map(int, input().split())) for _ in range(N)]

ans = "Found"
q = [(0, 0)]
while len(q) > 0:
    i, tmp = q.pop()
    if i == N:
        if tmp == 0: break
    else:
        for Tij in T[i]: q.append((i + 1, tmp ^ Tij))        
else:
    ans = "Nothing"

print(ans)