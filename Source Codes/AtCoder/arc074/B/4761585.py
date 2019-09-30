import heapq

N = int(input())
A = list(map(int, input().split()))

left = A[:N]
lefty = sum(left)
right = [-A[i] for i in range(3*N-1, 2*N-1, -1)]
righty = sum(right)
left_list = [lefty]
right_list = [righty]

heapq.heapify(left)
heapq.heapify(right)


for i in range(N, 2*N):
    heapq.heappush(left, A[i])
    x = heapq.heappop(left)
    lefty += A[i] - x
    left_list.append(lefty)

for i in range(2*N-1, N-1, -1):
    heapq.heappush(right, -A[i])
    y = heapq.heappop(right)
    righty += -A[i] - y
    right_list.append(righty)

ans = - float('inf')
for i in range(len(left_list)):
    ans = max(ans, left_list[i]+right_list[len(right_list)-1-i])

print(ans)