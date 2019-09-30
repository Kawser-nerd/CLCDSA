n,*h=map(int,open(0).readlines())
m=1
for t in range(n):
  s,u=t-(t>0),t+(t<n-1)
  if h[s]<h[t]>h[u]or t<1or t>n-2:
    while s and h[s-1]<h[s]:s-=1
    while u<n-1and h[u+1]<h[u]:u+=1
  m=max(m,u-s+1)
print(m)