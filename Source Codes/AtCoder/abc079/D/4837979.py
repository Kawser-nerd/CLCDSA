h,w = map(int,input().split())
C = [list(map(int,input().split())) for i in range(10)]
A = [list(map(int,input().split())) for i in range(h)]
inf = float('inf')
cost = 0
D = [[inf]*10 for i in range(10)]
for k in range(10):
    for i in range(10):
        for j in range(10):
            D[i][j] = min(C[i][j],C[i][k]+C[k][j])
for k in range(10):
    for i in range(10):
        for j in range(10):
            D[i][j] = min(D[i][j],D[i][k]+D[k][j])

for y in range(h):
    for x in range(w):
        if A[y][x] == -1 or A[y][x] == 1:
            continue
        else:
            cost += D[A[y][x]][1]

print(cost)