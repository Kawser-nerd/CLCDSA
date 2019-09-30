N,M,C=map(int,input().split())
stand=list(map(int,input().split()))
temp=[list(map(int,input().split())) for _ in range(N)]

res=0
for t in temp:
  ans=0
  for i in range(M):
    ans+=stand[i]*t[i]
  if ans+C>0:
    res+=1

print(res)