n,z,w = map(int,input().split())
lis = list(map(int,input().split()))
ans = 0
ans = max(ans,abs(lis[n-1]-w),abs(lis[n-1]-lis[n-2]))
print(ans)