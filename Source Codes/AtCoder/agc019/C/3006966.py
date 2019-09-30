x1,y1,x2,y2=map(int,input().split())
fx=1
fy=1
if x1>x2:
	x1,x2=x2,x1
	fx=-1
if y1>y2:
	y1,y2=y2,y1
	fy=-1

n=int(input())
p=[]
for i in range(n):
	x,y=map(int,input().split())
	if x1<=x<=x2 and y1<=y<=y2:
		p.append((fx*x,fy*y))
p=[y for x,y in sorted(p)]

from bisect import bisect_left as bl

b=[]

for y in p:
	pos=bl(b,y)
	if len(b)<=pos:
		b.append(y)
	else:
		b[pos]=y
	
from math import pi

l=len(b)

if l==min(x2-x1,y2-y1)+1:
	print(100*(x2-x1+y2-y1)+(5*pi-20)*(l-1)+(10*pi-20))
else:
	print(100*(x2-x1+y2-y1)+(5*pi-20)*l);