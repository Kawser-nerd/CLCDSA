n=int(input())
arr=[int(input()) for _ in range(n)]
arr=sorted(arr)
print(int(sum(arr)-arr[-1]/2))