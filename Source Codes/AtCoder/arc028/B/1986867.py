import heapq
N,K = map(int,input().split())
X = list(map(int,input().split()))

h = []
for rank, x in enumerate(X, start=1):
	heapq.heappush(h, (-x, rank))
	if rank < K:
		continue
	if rank == K:
		print(h[0][1])
		continue
	heapq.heappop(h)
	print(h[0][1])