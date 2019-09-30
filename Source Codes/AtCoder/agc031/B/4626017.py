N=int(input()) 
clist=[-1]
mod=10**9+7

for i in range(N):
  t=int(input())
  if t==clist[-1]:
    continue
  clist.append(t)

del clist[0]
N = len(clist)

# print(clist)
colorlast=[-1]*(3*10**5)
poslp=[-1]*(N+1)

for e,c in enumerate(clist,1):
  if  colorlast[c]  !=  -1:
    poslp[e]=colorlast[c]
    colorlast[c]=e
  else:
    colorlast[c]=e


dp=[0]*(N+100)
dp[0]=1

for e,c in enumerate(clist,1):
  if poslp[e]==-1:
    dp[e]=(dp[e-1])%mod
  else:
    dp[e]=(dp[e-1]+dp[poslp[e]])%mod

# print(dp[:len(clist)+1])
print(dp[len(clist)]%mod)