from heapq import heappush, heappop


N = int(input())
a = list(map(int, input().split())) + [0]
hq = []
ans = 0

for i, n in enumerate(a):
    mul = 1
    while hq and hq[0][0] < -n:
        m, j, _mul = heappop(hq)
        ans += -m*(i-j) * _mul
        mul += _mul

    heappush(hq, (-n, i, mul))

print(ans)