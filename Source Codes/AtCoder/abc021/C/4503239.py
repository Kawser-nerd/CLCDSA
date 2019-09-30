def warshall_floyd(d):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                d[i][j] = min(d[i][j],d[i][k] + d[k][j])
    return d
n = int(input())
a,b = map(int,input().split())
M = int(input())
d = [[float("inf") for i in range(n)] for i in range(n)]    #d[i][j]??ij????(????????inf)
for i in range(M):
    x,y= map(int,input().split())    #x,y????z??????
    d[x-1][y-1] = 1      #??????????
    d[y-1][x-1] = 1
for i in range(n):
    d[i][i] = 0      #?????????????0
warshall_floyd(d)
dp = [0]*n
dp[a-1] = 1
for i in range(n):
    for j in range(n):
        if d[a-1][j] != i:
            continue
        for k in range(n):
            if d[a-1][k] == i+1 and d[j][k] == 1:
                dp[k] = (dp[k]+dp[j])%(10**9+7)
print(dp[b-1])