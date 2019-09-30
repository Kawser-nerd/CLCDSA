import heapq
N, M = map(int, input().split())
data = []
for i in range(M):
    a, b = map(int, input().split())
    heapq.heappush(data, (b, a))

cut = 0
answer = 0
for i in range(M):
    b, a = heapq.heappop(data)
    if cut <= a:
        answer += 1
        cut = b

print(answer)