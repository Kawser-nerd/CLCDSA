n,l=map(int,input().split())
arr=[int(input()) for _ in range(n)]
arr=sorted(arr)
ans=n
ans+=int((l-sum(arr))/arr[0])
print(ans)