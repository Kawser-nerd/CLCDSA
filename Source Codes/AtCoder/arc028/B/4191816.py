import heapq

N, K = map(int, input().split())
inputs = [(-int(item), index+1) for index, item in enumerate(input().split())]

ans = []
for i in range(K):
    ans.append(inputs[i])

heapq.heapify(ans)

for i in range(K, N):
    print(ans[0][1])
    heapq.heappushpop(ans, inputs[i])

print(ans[0][1])