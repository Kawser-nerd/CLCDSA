s=int(input())
arr=[s]
tmp=0
for i in range(10**6+1):
  if arr[i]%2==0:
    tmp=int(arr[i]/2)
  else:
    tmp=arr[i]*3+1
  if tmp in arr:
    print(i+2)
    break
  arr.append(tmp)