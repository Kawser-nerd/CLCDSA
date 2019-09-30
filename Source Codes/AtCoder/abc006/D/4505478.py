from bisect import bisect_left

N = int(input())
c = []
append = c.append
for i in range(N):
    append(int(input()))

dp = [c[0]]
for x in c[1:]:
    if dp[-1] < x:
        dp.append(x)
    else:
        dp[bisect_left(dp, x)] = x
print(len(c)-len(dp))