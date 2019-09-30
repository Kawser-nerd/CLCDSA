n=int(input())
d=dict()
for i in range(n):
  s=input()
  if s not in d:
    d[s]=1
  else:
    d[s]+=1
m=0
b=""
for a in d.keys():
  if d[a]>m:
    b=a
    m=d[a]
print(b)