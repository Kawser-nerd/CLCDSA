arr=list(map(int,input().split()))
n=int(input())
arr=sorted(arr)
print(arr[0]+arr[1]+arr[2]*(2**n))