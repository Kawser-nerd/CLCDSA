import sys
fin = sys.stdin.readline
from bisect import bisect_left
 
n = int(fin())
card = [int(fin()) for _ in range(n)]
 
incre_pro=[]#??????????k????????????????????
for i in card:
     point = bisect_left(incre_pro,i)
     if point == len(incre_pro):
          incre_pro.append(i)
     else:
          incre_pro[point] = i
     
print(n-len(incre_pro))