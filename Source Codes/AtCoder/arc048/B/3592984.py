from bisect import bisect_left,bisect_right
from collections import defaultdict as dd

n=int(input())
d=dd(lambda:{1:0,2:0,3:0})

l=[list(map(int,input().split())) for i in range(n)]
o=[]

for i,j in l:
  d[i][j]+=1
  o.append(i)
o.sort()

for i,j in l:
  win=bisect_left(o,i)
  lose=n-bisect_right(o,i)
  draw=0
  if j==1:
    win+=d[i][2]
    draw+=d[i][1]-1
    lose+=d[i][3]
  elif j==2:
    win+=d[i][3]
    draw+=d[i][2]-1
    lose+=d[i][1]
  elif j==3:
    win+=d[i][1]
    draw+=d[i][3]-1
    lose+=d[i][2]
  print(win,lose,draw)