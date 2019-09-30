import math
q=int(input())
cnt=0
Issame=True
remainder=1e10
sum=0
for j in range(q):
  a,b=[int(i) for i in input().split()]
  Issame=Issame if a==b else False 
  if a>b:
    remainder=min(remainder,b)
  sum+=a
if Issame:
  print(0)
else:
  print(sum-remainder)