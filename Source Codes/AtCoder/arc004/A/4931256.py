import math
 
n=int(input())
arr=[]
for i in range(n):
  arr.append(list(map(int,input().split())))
 
tmp=0
for i in range(n):
  for j in range(i,n):
    if (arr[j][0]-arr[i][0])**2 + (arr[j][1]-arr[i][1])**2 > tmp:
      tmp=(arr[j][0]-arr[i][0])**2 + (arr[j][1]-arr[i][1])**2
print(math.sqrt(tmp))