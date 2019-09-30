x1,y1,x2,y2,t,v=map(int,input().split())
n=int(input())
ans="NO"
for _ in range(n):
  x,y=map(int,input().split())
  if ((x-x1)**2+(y-y1)**2)**.5+((x-x2)**2+(y-y2)**2)**.5<=t*v:
    ans="YES"
    break
print(ans)