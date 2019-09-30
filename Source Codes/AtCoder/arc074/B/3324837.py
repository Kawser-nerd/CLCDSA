ai = lambda: list(map(int,input().split()))

n = int(input())
a = ai()

big = sum(a[:n])
small = sum(a[2*n:])

import heapq
af = a[:n]
heapq.heapify(af)
ar = [-i for i in a[2*n:]]
heapq.heapify(ar)

ans = [[0,0] for _ in range(n+1)]
ans[0][0] = big
ans[-1][1] = small

for k in range(n):
    if af[0] < a[n+k]:
        b = heapq.heapreplace(af, a[n+k])
        big += a[n+k] - b
    ans[k+1][0] = big

for k in range(n):
    if -ar[0] > a[-n-k-1]:
        s = heapq.heapreplace(ar, -a[-n-k-1])
        small += a[-n-k-1] + s
    ans[-k-2][1] = small

print(max(i-j for i,j in ans))