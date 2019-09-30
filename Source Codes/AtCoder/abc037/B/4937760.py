n,q=map(int,input().split())
Ans=[0]*n
for i in range(q):
  l,r,t=map(int,input().split())
  for j in range(r-l+1):
    Ans[l+j-1]=t
for a in Ans:
  print(a)