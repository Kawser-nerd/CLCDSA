from collections import Counter
import sys
h=w=index=0
n=int(input())
a=list(map(int,input().split()))
l=Counter(a)
l2=sorted(l.items(),reverse=True)
for i in range(len(l2)):
  if l2[i][1]>=2:
    if l2[i][1]>=4:
      print(l2[i][0]**2)
      sys.exit()
    w=l2[i][0]
    index=i
    break
for i in range(index+1,len(l2)):
  if l2[i][1]>=2:
    h=l2[i][0]
    break
print(h*w)