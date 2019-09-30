n,k,*a=map(int,open(0).read().split())
l=[]
t=0
for i,j in zip(a,a[1:]):
  if j>i:
    t+=1
  else:
    l.append(t)
    t=0
l.append(t)
print(sum(max(0,t+2-k)for t in l))