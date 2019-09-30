# seishin.py
N = int(input())
P = [list(map(int, input().split())) for i in range(N)]

from heapq import heappush, heappop

l0, r0 = P[0]

L = [-l0+1]
R = [l0-1]
s = t = 0

res = 0
for i in range(N-1):
    l0, r0 = P[i]
    l1, r1 = P[i+1]
    s += (r1 - l1); t += (r0 - l0)
    if -s-L[0] <= l1-1 <= t+R[0]:
        heappush(L, -l1+1-s)
        heappush(R, l1-1-t)
    elif l1-1 < -s-L[0]:
        heappush(L, -l1+1-s)
        heappush(L, -l1+1-s)
        p = -heappop(L)-s
        heappush(R, p-t)
        res += (p - (l1-1))
    elif t+R[0] < l1-1:
        heappush(R, l1-1-t)
        heappush(R, l1-1-t)
        p = heappop(R) + t
        heappush(L, -p-s)
        res += ((l1-1) - p)
print(res)