n,*a=map(int,open(0).read().split());f=[0]*10**6;l=c=0
for r in range(n):
 while f[a[r]]:f[a[l]]-=1;l+=1
 f[a[r]]+=1;c=max(c,r-l+1)
print(c)