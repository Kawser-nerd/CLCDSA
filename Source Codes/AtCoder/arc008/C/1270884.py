from math import hypot
def dijkstra(matrix):
	from heapq import heappush, heappop
	n = len(matrix)
	inf = 10**10
	hq = []
	ans = [inf]*n
	ans[0] = 0
	heappush(hq, (0, 0))
	while hq:
		d, p = heappop(hq)
		for i in range(n):
			if ans[p] == d and p != i and d + matrix[p][i] < ans[i]:
				ans[i] = d + matrix[p][i]
				heappush(hq, (ans[i], i))
	return ans

N = int(input())
if N == 1:
	print(0)
	exit()

C = [[int(i) for i in input().split()] for j in range(N)]
G = [[0]*N for i in range(N)]
for i in range(N):
	for j in range(i,N):
		d = hypot(C[i][0]-C[j][0], C[i][1]-C[j][1])
		G[i][j] = d / min(C[i][2], C[j][3])
		G[j][i] = d / min(C[j][2], C[i][3])

ans = dijkstra(G)
ans.sort(reverse=True)
print(max([ans[i] + i  for i in range(N-1)]))