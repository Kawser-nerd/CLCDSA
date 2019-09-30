N = int(input())
train = [[] for _ in range(N)]
L = []
for cnt in range(N - 1):
    l = list(map(int,input().split()))
    L.append(l)

from math import ceil

from bisect import bisect_left
for place in range(N):
    now = 0
    for i in range(place,N - 1):
        k = max(0,ceil((now - L[i][1]) / L[i][2]))
        now = L[i][1] + L[i][2] * k
        now += L[i][0]
    print(now)