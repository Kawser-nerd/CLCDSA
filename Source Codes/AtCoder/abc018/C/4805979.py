r,c,k = map(int,input().split())
S = [list(input()) for i in range(r)]
imos = [[0]*(c+1) for i in range(r)]

for i in range(r):
    for j in range(c):
        if S[i][j] == 'x':
            for kk in range(k):
                if i-kk >= 0:
                    imos[i-kk][max(0,j-k+kk+1)] += 1
                    imos[i-kk][min(c,j+k-kk)] -= 1
                if i+kk < r:
                    imos[i+kk][max(0,j-k+kk+1)] += 1
                    imos[i+kk][min(c,j+k-kk)] -= 1

for i in range(r):
    for j in range(1,c+1):
        imos[i][j] += imos[i][j-1]

ans = 0
for y in range(k-1, c-k+1):
    for x in range(k-1, r-k+1):
        if imos[x][y] == 0:
            ans += 1
print(ans)