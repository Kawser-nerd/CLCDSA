from bisect import bisect_left
 
n = int(input())
card = [int(input()) for i in range(n)]
incre_pro=[]#??????????k????????????????????
for i in card:
     point = bisect_left(incre_pro,i)
     if point == len(incre_pro):
          incre_pro.append(i)
     else:
          incre_pro[point] = i
     
print(n-len(incre_pro))