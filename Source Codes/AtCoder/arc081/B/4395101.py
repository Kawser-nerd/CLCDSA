N=int(input())
S=[input() for _ in range(2) ]
dp=[0]*(N+1)
dp[0]=1
mod=10**9+7
i=0
st=0
while i<N:
  if S[0][i]==S[1][i] and st==0:
    dp[i+1]=dp[i]*3
    st=1
  elif S[0][i]==S[1][i] and st==1:
    dp[i+1]=dp[i]*2%mod
  elif S[0][i]==S[1][i] and st==2:
    dp[i+1]=dp[i]
    st=1
  elif S[0][i]!=S[1][i] and st==0:
    dp[i+2]=dp[i]*6
    st=2
  elif S[0][i]!=S[1][i] and st==1:
    dp[i+2]=dp[i]*2%mod
    st=2
  elif S[0][i]!=S[1][i] and st==2:
    dp[i+2]=dp[i]*3%mod
  if S[0][i]==S[1][i]:
    i+=1
  else:
    i+=2
print(dp[N]%mod)