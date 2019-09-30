x=lambda:input().split()
n,_=x();a=x();n=int(n)
while any(s in set(a)for s in str(n)):n+=1
print(n)