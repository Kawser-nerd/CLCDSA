N, K = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort(reverse=True)
ans = 0
for i in range(K):
    ans += nums[i]
print(ans)