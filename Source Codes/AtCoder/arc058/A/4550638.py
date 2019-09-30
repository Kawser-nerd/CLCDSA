n,k,*a=open(0).read().split();n=int(n)
while any(s in set(a)for s in str(n)):n+=1
print(n)