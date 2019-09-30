W=int(input())
N,K=map(int,input().split())
dp=[[10000000]*(K+1) for v in range(5001)]
v_max=0
V=0
for n in range(N):
  width,value=map(int,input().split())
  V+=value
  for v in range(V,-1,-1):
    for k in range(min(n+1,K),-1,-1):
      if v==0:
        if k==0:
          dp[v][k]=0
      elif k==0:
        pass
      elif n==0:
        if k==1 and v==value:
          dp[v][1]=width
        else:
          pass
      else:
        if v>=value:
          dp[v][k]=min(dp[v-value][k-1]+width,dp[v][k])
        else:
          dp[v][k]=dp[v][k]
      if n==N-1 and v_max<v and dp[v][k]<=W:
        v_max=v
print(v_max)