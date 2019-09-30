N = int(input())
D = [list(map(int, input().split())) for i in range(N)]
Q = int(input())
P = [int(input()) for i in range(Q)]

mem_rec = [[0 for i in range(N)] for j in range(N)]
mem_max = [[-1 for i in range(N)] for j in range(N)]

mem_rec[0][0] = D[0][0]

for i in range(1, N) :
	mem_rec[0][i] = D[0][i] + mem_rec[0][i-1]
	mem_rec[i][0] = D[i][0] + mem_rec[i-1][0]
	
for x in range(1, N) :
	for y in range(1, i+1) :
		mem_rec[y][x] = D[y][x] + mem_rec[y][x-1] + mem_rec[y-1][x] - mem_rec[y-1][x-1]
		
		if x != y :
			mem_rec[x][y] = D[x][y] + mem_rec[x][y-1] + mem_rec[x-1][y] - mem_rec[x-1][y-1]

def size(p) :
	if N * N <= p : return mem_rec[N-1][N-1]
	
	res = 0
	for x in range(max(1, p // N) , N+1) :		
		if p < x * x : break
		
		y = min(N, p // x)
		if mem_max[y-1][x-1] == -1 :
			if x == y :
				mem_max[y-1][x-1] = calc(x, y)
			else :
				mem_max[y-1][x-1] = max(calc(x, y), calc(y, x))
		
		res = max(res, mem_max[y-1][x-1])
			
	return res
			
def calc(x, y) :
	res = 0
	for i in range(x-1, N) :
		for j in range(y-1, N) :
			tmp = mem_rec[j][i]
			if i-x >= 0 : tmp -= mem_rec[j][i-x]
			if j-y >= 0 : tmp -= mem_rec[j-y][i]
			if i-x >= 0 and j-y >= 0 : tmp += mem_rec[j-y][i-x]
			res = max(res, tmp)
			
	return res

for p in P :
	print(size(p))