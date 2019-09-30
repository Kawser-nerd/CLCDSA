n = int(input())
s,a,b = 0,0,0
f = True
for _ in [0]*n:
  t,x,y = map(int,input().split())
  p = t-s-(abs(x-a)+abs(y-b))
  if p%2 == 1 or p<0:
    f = False
print("Yes" if f else "No")