n,k,*a=open(0).read().split()
while set(a)&set(n):n=str(int(n)+1)
print(n)