N,K=[int(i) for i in input().split()]
r=[int(i)for i in input().split()]
r=sorted(r)
res=0
for i in range(N-K,N):
  res=(res+r[i])/2
print(res)