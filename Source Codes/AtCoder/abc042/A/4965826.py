a,b,c=map(int,input().split())
arr=[a,b,c]
arr=sorted(arr)
if arr[0]==arr[1]==5 and arr[2]==7:
  print('YES')
else:
  print('NO')