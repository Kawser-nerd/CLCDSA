#????????Longest Increasing Subsequence?
def LIS(N,a):
  """?????N, ??a???????????
  ????N^2"""
  res=0
  dp=[1]*N#???a[i] ?????????????????
  for i in range(N):
    for j in range(i):
      if XY[j][0]<XY[i][0] and XY[j][1]<XY[i][1]:
        dp[i]=max(dp[i],dp[j]+1)
    res=max(res,dp[i])
  return res

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
from bisect import bisect
 
# find LIS
XY.sort()
XY = [y for x,y in XY]

dp = [H+1]*len(XY)
 
for i,f in enumerate(XY):
  dp[bisect(dp,f)] = f
fountain = bisect(dp,H)
if fountain<min(W,H)+1:
  print(straight-short*fountain)
else:
  print(straight-short*(fountain-1)+long)