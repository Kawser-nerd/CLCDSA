import heapq

N, K = map(int, input().split())
X = list(map(int, input().split()))

hq = [(-X[i], i+1) for i in range(K)]
heapq.heapify(hq)
for i in range(K, N):
    print(hq[0][1])
    heapq.heappushpop(hq, (-X[i], i+1))

print(hq[0][1])