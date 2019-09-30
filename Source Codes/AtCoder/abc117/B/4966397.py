n=int(input())
arr=list(map(int,input().split()))
arr=sorted(arr)
total=sum(arr[:-1])
if arr[-1]<total:
  print('Yes')
else:
  print('No')