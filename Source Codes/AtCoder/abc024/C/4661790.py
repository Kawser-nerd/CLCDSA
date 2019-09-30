n,d,k=map(int,input().split())
LR=[list(map(int,input().split())) for i in range(d)]
ST=[list(map(int,input().split())) for i in range(k)]
days=[]
for s,t in ST:
  tmp=0
  for l,r in LR:
    tmp+=1
    if l<=s<=r and l<=t<=r:
      print(tmp)
      break
    if l<=s<=r:
      if abs(t-r)<abs(t-l):
        s=r
      else:
        s=l