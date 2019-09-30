n=int(input())
a=[]
for i in range(n):
  a.append([int(i) for i in input().split()])
ans=0
for i in range(n):
  x1,y1=a[i]
  for j in range(i):
    x2,y2=a[j]
    for k in range(j):
      x3,y3=a[k]
      m=abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))
      if m % 2==0 and m!=0:
        ans+=1
print(ans)