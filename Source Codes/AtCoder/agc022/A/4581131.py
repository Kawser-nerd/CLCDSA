s=input()
b="abcdefghijklmnopqrstuvwxyz"
from collections import defaultdict 
if len(s)<26:
  d=defaultdict(int)
  for c in s:
    d[c]+=1
  for bb in b:
    if d[bb]==0:
      print(s+bb)
      exit() 
N=len(s)
lst=[]
for first in range(N-1,0,-1):
  mn=s[first]
  for i in range(first-1,-1, -1):
    if s[i]<mn:
      lst.append(s[:i]+mn)
      #print(s[:i]+mn)
      #exit()
if lst:
  print(sorted(lst)[0])
  exit()
print(-1)