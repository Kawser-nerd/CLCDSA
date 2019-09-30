I=lambda:list(map(int,input().split()))
n,x=I()
r=range(n+1)
H=[0]+I()
T=[[]for i in r]
for i in range(n-1):
  a,b=I()
  T[a]+=[b]
  T[b]+=[a]
while 1:
  for i in r:
    if all([len(T[i])==1,H[i]<1,i!=x]):
      T[T[i].pop()].remove(i);break
  else:break
print(sum(len(t)for t in T))