N, C = map(int, input().split())
D = [[int(i) for i in input().split()] for i in range(C)]

L = [[0] * C for i in range(3)]
for i in range(N):
    X = [int(i) for i in input().split()]
    for j in range(N):
        L[(i + j) % 3][X[j] - 1] += 1
        
ans = float('inf')
for i in range(C):
    for j in range(C):
        for k in range(C):
            if i != j and j != k and k != i:
                tmp = 0
                for x in range(C):
                    tmp += L[0][x] * D[x][i] + L[1][x] * D[x][j] + L[2][x] * D[x][k]
                ans = min(ans, tmp)
                    
print(ans)