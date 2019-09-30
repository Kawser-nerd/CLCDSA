import heapq
N, K = map(int, input().split())
A = list(map(int, input().split()))
ans = []
for i in range(K):
    ans.append([-A[i], i+1])

heapq.heapify(ans)
for i in range(K, N):
    print(ans[0][1])
    heapq.heappushpop(ans, [-A[i], i+1])
print(ans[0][1])