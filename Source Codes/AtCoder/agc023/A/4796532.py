from collections import defaultdict

# ??
N = int(input())
A = list(map(int, input().split()))

# dp[s]: A_1 + ... + A_i = s ?????? i ???
dp = defaultdict(int, {0: 1})
# ?
s = 0
# ?
ans = 0
# ?i????? A_1 + ... + A_i = A_1 + ... + A_j ?????? 0 <= j < N ???????
for a in A:
    s += a
    ans += dp[s]
    dp[s] += 1

# ??
print(ans)