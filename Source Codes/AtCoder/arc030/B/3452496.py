I=lambda:list(map(int,input().split()))
n,x=I()
H=[0]+I()

T=[[] for i in range(n+1)]
for i in range(n-1):
  a,b=I()
  T[a]+=[b]
  T[b]+=[a]

while True:
  f = 1
  for i in range(n+1):
    if len(T[i])==1 and H[i] == 0 and i != x:
      f =0
      j = T[i][0]
      T[i].remove(j)
      T[j].remove(i)
  if f:break
    
print(sum(len(t)for t in T))