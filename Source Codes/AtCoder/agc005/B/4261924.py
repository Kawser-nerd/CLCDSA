import heapq


n = int(input())
a = list(map(int, input().split()))

d = {}
for i, a_ in enumerate(a):
    d[a_] = i


h = []
right = [n-1] * n

for i in range(n):
    while h and -h[0] > a[i]:
        v = -heapq.heappop(h)
        right[d[v]] = i - 1
    heapq.heappush(h, -a[i])

h = []
left = [0] * n

for i in reversed(range(n)):
    while h and -h[0] > a[i]:
        v = -heapq.heappop(h)
        left[d[v]] = i + 1
    heapq.heappush(h, -a[i])

ans = 0
for i in range(n):
    ans += a[i] * (i - left[i] + 1) * (right[i] - i + 1)

print(ans)