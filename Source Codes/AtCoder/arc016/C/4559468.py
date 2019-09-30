n,m = map(int,input().split())

cost = []
gatya = [[0  for j in range(10)] for i in range(m)]
#gatya[i][j] = i???????????j?????

for i in range(m):
    c,co = map(int,input().split())
    cost.append(co)
    for j in range(c):
        idol,p = map(int,input().split())
        idol -= 1
        gatya[i][idol] = p


dp = [float('inf') for i in range(1 << n)]

dp[(1 << n)-1]=0

def dfs(bit):
    if dp[bit] != float('inf'):return dp[bit]
    exp = float('inf')
    for i in range(m):
        ex = 0
        p = []
        sum = 0
        for j in range(n):
            if (gatya[i][j] != 0) and ((1 << j) & bit) == 0:
                p.append(j)
                sum += gatya[i][j]
        if len(p) == 0:continue
        for j in p:
            ex += (dfs(bit | (1 << j)) + 100/(sum)*cost[i]  )*(gatya[i][j])/sum
        if exp > ex: exp = ex
    
    dp[bit] = exp
    return exp
        
    
print(dfs(0))