from itertools import *
n,k = map(int,input().split())
nums = list(map(int,input().split()))
acl = list(accumulate(nums))
ans = acl[k-1]
for i in range(n):
    try:
        ans += acl[i+k] - acl[i]
    except:
        pass
print(ans)