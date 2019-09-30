def LIS(L):
  from bisect import bisect
  seq=[]
  for i in L:
    pos=bisect(seq,i)
    if len(seq)<=pos:
      seq.append(i)
    else:
      seq[pos]=i
  return len(seq)
 
import math 
x1,y1,x2,y2=map(int,input().split())
N=int(input())
W=abs(x2-x1)
H=abs(y2-y1)
xsgn=2*(x2>x1)-1
ysgn=2*(y2>y1)-1
XY=[]
for i in range(N):
  x,y=map(int,input().split())
  if (x-x1)*(x-x2)<=0 and (y-y1)*(y-y2)<=0:
    XY+=[[xsgn*(x-x1),ysgn*(y-y1)]]
short=20-5*math.pi
long=10*math.pi-20
straight=100*(W+H)
 
XY.sort()
Y = [y for x,y in XY]
 
fountain=LIS(Y)
 
if fountain<min(W,H)+1:
  print(straight-short*fountain)
else:
  print(straight-short*(fountain-1)+long)