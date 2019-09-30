N, M = map(int, input().split())
A = list(map(int, input().split()))

# ??k??????????????
def num(k):
    costs = [2, 5, 5, 4, 5, 6, 3, 7, 6]
    return costs[k-1]

# ?????
# dp(i) := i??????(i = 0,1,...,N)
# constructor
inf = 1000
# -inf?????????????????
dp = [-inf for _ in range(N+1)]
dp[0] = 0

cost_list = [num(k) for k in A]
for i in range(1, N+1):
    for cost in cost_list:
        if i - cost < 0:
            pass
        else:
            temp = dp[i - cost] + 1
            dp[i] = max(dp[i], temp)

ans = ''
many = N
for d in range(dp[N]): # ??
    for k in sorted(A, reverse=True):
        if many - num(k) < 0:
            pass
        else:
            if dp[many - num(k)] == dp[many] - 1:
                ans += str(k)
                many -= num(k)
                break
            else:
                pass

print(int(ans))