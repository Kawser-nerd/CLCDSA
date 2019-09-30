N = int(input())
a,b = map(int,input().split())
M = int(input())
a -= 1
b -= 1

INF = float('inf')
mat=[[INF]*N for i in range(N)]

for i in range(N):
    mat[i][i] = 0


for _ in range(M):
    x,y = map(int,input().split())
    mat[x-1][y-1] = 1
    mat[y-1][x-1] = 1
    


for i in range(N):
	for x in range(N):
		for y in range(N):
			mat[x][y] = min(mat[x][y], mat[x][i] + mat[i][y])



mod = 10**9+7
num = [0]*N
num[a] = 1

for r in range(N):
    for x in range(N):
        if mat[a][x] != r:
            continue
        for y in range(N):
            if mat[a][y] == r+1 and mat[x][y] == 1:
                num[y] += num[x]
                num[y] %= mod

print(num[b])