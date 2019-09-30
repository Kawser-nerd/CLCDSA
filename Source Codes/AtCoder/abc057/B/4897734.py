(n,m),*a=[list(map(int,s.split()))for s in open(0)]
for i,j in a[:n]:l=[abs(x-i)+abs(y-j)for x,y in a[n:]];print(1+l.index(min(l)))