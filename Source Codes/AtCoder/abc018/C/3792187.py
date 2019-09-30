R, C, K = map(int, input().split())
imos = [[0]*(C+1) for _ in range(R)]
for i in range(R):
    s = input()
    for j in range(C):
        if s[j] == "x":
            for k in range(K):
                if i-k >= 0:
                    imos[i-k][max(0,j-K+k+1)] += 1
                    imos[i-k][min(C,j+K-k)] -= 1
                if i+k < R:
                    imos[i+k][max(0,j-K+k+1)] += 1
                    imos[i+k][min(C,j+K-k)] -= 1
for i in range(R):
    for j in range(1, C+1):
        imos[i][j] += imos[i][j-1]

res = 0
for y in range(K-1, C-K+1):
    for x in range(K-1, R-K+1):
        if imos[x][y] <= 0:
            res += 1
print(res)