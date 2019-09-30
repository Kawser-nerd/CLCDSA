N = int(input())
D = [list(map(int, input().split())) for i in range(N)]
Q = int(input())
P = [int(input()) for i in range(Q)]

mem_rec = [[0 for i in range(N+1)] for j in range(N+1)]
mem_max = [0 for i in range(N*N+1)]

for x in range(1, N+1) :
	for y in range(1, x) :
		mem_rec[y][x] = D[y-1][x-1] + mem_rec[y][x-1] + mem_rec[y-1][x] - mem_rec[y-1][x-1]
		mem_rec[x][y] = D[x-1][y-1] + mem_rec[x][y-1] + mem_rec[x-1][y] - mem_rec[x-1][y-1]
	mem_rec[x][x] = D[x-1][x-1] + mem_rec[x][x-1] + mem_rec[x-1][x] - mem_rec[x-1][x-1]
	
def calc(x, y) :
	res = 0
	for i in range(x, N+1) :
		for j in range(y, N+1) :
			tmp = mem_rec[j][i] - mem_rec[j][i-x] - mem_rec[j-y][i] + mem_rec[j-y][i-x]
			res = max(res, tmp)
			
	return res
	
for x in range(1 , N+1) :
	mem_max[x*x] = max(calc(x, x), mem_max[x*x])
	for y in range(x+1, N+1) :
		mem_max[x*y] = max(calc(x, y), calc(y, x), mem_max[x*y])

for i in range(1, N*N+1) :
	mem_max[i] = max(mem_max[i-1], mem_max[i])

for p in P :
	print(mem_max[p])