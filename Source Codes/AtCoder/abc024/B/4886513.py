n,m=map(int,input().split())
l=[]
t=0
for i in range(n):
  l.append(int(input()))
for i in range(n-1):
  if l[i+1]-l[i]<m:
    t+=l[i+1]-l[i]
  else:
    t+=m
print(t+m)