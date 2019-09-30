n=int(input())
d,x=map(int,input().split())
a=[]
for i in range(n):
  a.append(int(input()))
s=0
for i in range(n):
  for j in range(d):
    if a[i]*j+1<=d:
      s+=1
print(s+x)