import heapq
n,k = map(int,input().split())
x = list(map(int,input().split()))

h = []
for r, a in enumerate(x,1):
  if r <= k:
    heapq.heappush(h, (-a, r))
  else:
    heapq.heappushpop(h, (-a, r))
  
  if r >= k:
    print(h[0][1])