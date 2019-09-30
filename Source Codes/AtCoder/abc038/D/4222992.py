# -*- coding: utf-8 -*-

N = int(input())
S = []
for _ in range(N):
    w, h = map(int, input().split())
    S.append((w, h))

S.sort(key=lambda x:x[0], reverse=True)
S.sort(key=lambda x:x[1])

# Method 2
import bisect
DP = []
for i in range(N):
    wi, hi = S[i]
    idx = bisect.bisect_left(DP, wi)
    if len(DP) == idx:
        DP.append(wi)
    else:
        DP[idx] = wi

print(len(DP))