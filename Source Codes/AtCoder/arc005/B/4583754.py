x,y,w=input().split()
c=[input()for _ in range(9)]
x,y=int(x)-1,int(y)-1
ans=''
dx,dy=0,0
if "R" in w:dx=1
if "L" in w:dx=-1
if "U" in w:dy=-1
if "D" in w:dy=1
def turn():
  global x,y,dx,dy
  if x+dx<0 or 8<x+dx:dx*=-1
  if y+dy<0 or 8<y+dy:dy*=-1
for i in range(4):
  cij=c[y][x]
  ans+=cij
  turn()
  x+=dx
  y+=dy
print(ans)