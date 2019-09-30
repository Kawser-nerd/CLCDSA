n = int(input())
a, b = map(int, input().split())
m = int(input())
a -= 1
b -= 1
INF = float('inf')
mat = [[INF] * n for _ in range(n)]  # dp table

for i in range(n):
    mat[i][i] = 0
for _ in range(m):
    x, y = map(int, input().split())
    mat[x - 1][y - 1] = 1
    mat[y - 1][x - 1] = 1

for i in range(n):
    for j in range(n):
        for k in range(n):
            mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k])

mod = 10 ** 9 + 7
num = [0] * n
num[a] = 1

for i in range(n):
    for j in range(n):
        if mat[a][j] != i:
            continue
        for k in range(n):
            if mat[a][k] == i + 1 and mat[j][k] == 1:
                num[k] += num[j]
                num[k] %= mod
print(num[b])