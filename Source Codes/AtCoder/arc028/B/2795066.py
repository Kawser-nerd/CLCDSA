import heapq
N, K = map(int, input().split())
X = list(map(int, input().split()))

A = []
for i in range(K):
    A.append((-X[i], i+1))

heapq.heapify(A)
for i in range(K, N):
    print(A[0][1])
    heapq.heappushpop(A, (-X[i], i+1))
print(A[0][1])