x,y,w=input().split()
x,y=int(x)-1,int(y)-1
d=['R'in w or-('L'in w),'D'in w or-('U'in w)]
m=[input()for _ in range(9)]
a=m[y][x]
for _ in range(3):
  x,y=x+d[0],y+d[1]
  if x<0:
    d[0]=1
    x=1
  elif x>8:
    d[0]=-1
    x=7
  if y<0:
    d[1]=1
    y=1
  elif y>8:
    d[1]=-1
    y=7
  a+=m[y][x]
print(a)