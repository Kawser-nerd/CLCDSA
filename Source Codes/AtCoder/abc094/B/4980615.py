n,m,x=map(int,input().split())
arr=list(map(int,input().split()))
count1=0
count2=0
for i in range(m):
  if arr[i]<x:
    count1+=1
  elif arr[i]>x:
    count2+=1
print(min(count1,count2))