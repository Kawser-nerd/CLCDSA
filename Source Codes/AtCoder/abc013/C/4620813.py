N,H=map(int,input().split())
A,B,C,D,E=map(int,input().split())
inf=float('inf')
dp=[inf]*(N+1)
dp[0]=C*N
for i in range(1,1+N):
    cost=C*(N-i)
    hung=H+D*(N-i)-E*i
    if hung>0:dp[i]=cost
    else:
        inc=1+(abs(hung))//(B-D)
        if inc>N-i:break
        cost+=(A-C)*inc
        dp[i]=cost
print(min(dp))