n=int(input())
arr=list(map(int,input().split()))
arr=sorted(arr)
print(abs(arr[-1]-arr[0]))