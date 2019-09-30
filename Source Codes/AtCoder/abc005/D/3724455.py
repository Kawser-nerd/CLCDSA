n = int(input())
d = [list(map(int, input().split())) for i in range(n)]
q = int(input())
p = [int(input()) for i in range(q)]

for i in range(n):
    for j in range(n-1):
        d[i][j+1] += d[i][j]
for j in range(n):
    for i in range(n-1):
        d[i+1][j] += d[i][j]

taste = [[0 for i in range(n+10)] for j in range(n+10)]

for i in range(n):
    for j in range(n):
        for k in range(n-i):
            for l in range(n-j):
                if k == 0 and l == 0:
                    taste[i][j] = max(taste[i][j], d[i][j])
                elif k == 0:
                    taste[i][j] = max(taste[i][j], d[i+k][j+l] - d[i+k][l-1])
                elif l == 0:
                    taste[i][j] = max(taste[i][j], d[i + k][j + l] - d[k - 1][j + l])
                else:
                    taste[i][j] = max(taste[i][j], d[i + k][j + l] - d[i+k][l-1] - d[k-1][j+l] + d[k-1][l-1])

for num in p:
    taste_max = 0
    for i in range(n):
        for j in range(n):
            if (i+1) * (j+1) <= num:
                taste_max = max(taste_max, taste[i][j])
    print(taste_max)