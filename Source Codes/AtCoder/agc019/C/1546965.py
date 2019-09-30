#????????Longest Increasing Subsequence?
def LIS(L):
  """??L???????????
  ????NlogN"""
  from bisect import bisect
  best=[]
  for i in L:
    pos=bisect(best,i)
    if len(best)<=pos:
      best.append(i)
    else:
      best[pos]=i
  return len(best)

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
N=len(XY)
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