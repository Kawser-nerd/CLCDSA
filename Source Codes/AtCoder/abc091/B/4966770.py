n=int(input())
arr1=[input() for _ in range(n)]
m=int(input())
arr2=[input() for _ in range(m)]
max=0
for i in range(n):
  tmp=arr1.count(arr1[i])-arr2.count(arr1[i])
  if tmp>max:
    max=tmp
print(max)