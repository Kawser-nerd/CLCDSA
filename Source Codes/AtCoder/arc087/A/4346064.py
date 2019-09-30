n,*a=map(int,open(0).read().split())
d={}
for i in a:d[i]=d.get(i,0)+1
print(sum(d[i]-i*(d[i]>=i)for i in d))