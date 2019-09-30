n, m, q = (int(i) for i in input().split())
city = [[0 for i in range(n+1)] for j in range(n+1)]

for i in range(m):
    l, r = (int(i) for i in input().split())
    city[l][r] += 1
for i in range(1, n+1):
    for j in range(1, n+1):
        city[i][j] += city[i][j-1]
for i in range(1, n+1):
    for j in range(1, n+1):
        city[i][j] += city[i-1][j]


for i in range(q):
    a, b = (int(i) for i in input().split())
    print(city[b][b] - city[a-1][b] - city[b][a-1] + city[a-1][a-1])