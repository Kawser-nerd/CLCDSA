N,A,B=map(int,input().split())

L=[]
for i in range(N):
    a,b,c=map(int,input().split())
    L.append([a,b,c])
#print(L)

dp=[[100000 for i in range(401)]for j in range(401)]
dp[0][0]=0

for n in range(N):
    for i in range(401):
        for j in range(401):
            if dp[400-i][400-j]<100000:
                if 400-i+L[n][0]<=400 and 400-j+L[n][1]<=400:
                    if dp[400-i+L[n][0]][400-j+L[n][1]]>dp[400-i][400-j]+L[n][2]:
                        dp[400-i+L[n][0]][400-j+L[n][1]]=dp[400-i][400-j]+L[n][2]
ans=100000
for i in range(1,401):
    for j in range(1,401):
        if i*B==j*A and ans>dp[i][j]:
            ans=dp[i][j]
if ans<100000:
    print(ans)
else:
    print(-1)
#print(dp)