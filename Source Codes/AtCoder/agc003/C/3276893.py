n,*a=map(int,open(0).read().split())
b={}
c=0
for i,t in zip(range(n),sorted(a)):
  b[t]=i%2
for i,t in zip(range(n),a):
  c+=i%2!=b[t]
print(c//2)