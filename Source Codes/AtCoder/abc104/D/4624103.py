s=input()

n=len(s)
dc=dict()
dc['A']=0
dc['B']=1
dc['C']=2
dc['?']=3
dp=[[0 for i in range(4)] for j in range(n+1)]
dp[0][0]=1
mo=10**9+7
for i in range(n):
    for t in range(4):
        ch=s[i]
        m = 1 if dc[ch]==t-1 or dc[ch]==3 else 0
        if t!=0:
            dp[i+1][t]+=(dp[i][t-1]*m)%mo
        dp[i+1][t]+=(dp[i][t]*(3 if dc[ch]==3 else 1))%mo

ans=dp[n][3]
print(ans%mo)