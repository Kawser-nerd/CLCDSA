a,b,c=map(int,input().split())
arr=[a,b,c]
arr=sorted(arr)
print(10*arr[-1]+arr[1]+arr[0])