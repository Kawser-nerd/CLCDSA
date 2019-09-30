N,T=map(int,input().split())
cost=10**3
ans=0
for i in range(N):
  c,t=map(int,input().split())
  if t<=T:
    if c<=cost:
      cost=c
      ans=i+1
if ans==0:
  print("TLE")
else:
  print(cost)