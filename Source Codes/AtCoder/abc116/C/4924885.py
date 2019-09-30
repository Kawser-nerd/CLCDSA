N=int(input())
height=[int(i) for i in input().split()]
height.append(0)
count=0
for i in range(N):
  while height[i]>0:
    j=0
    while height[i+j]>0:
      height[i+j]=height[i+j]-1
      j=j+1        
    count+=1
print(count)