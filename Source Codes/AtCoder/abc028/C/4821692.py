from heapq import heappop, heappush

a = list(map(int, input().split()))

t = []
for i in range(4):
    for j in range(i+1, 5):
        heappush(t, a[i] + a[j])

heappop(t)
heappop(t)

print(sum(a) - heappop(t))