from itertools import permutations,cycle
n,c=map(int,input().split())
v=float("inf")
a=[int(input()) for _ in range(n)]
colors=set(a)
if len(colors)==1:
  b=set(range(1,11))-colors
  colors.add(b.pop())

for i in permutations(colors,2):
  l=[]
  cost=0
  for i,j in enumerate(cycle(i)):
    if not i<n:break
    l.append(j)
  for i,j in zip(a,l):
    if i!=j:cost+=c
  v=min(v,cost)

print(v)