matches = [0, 2, 5, 5, 4, 5, 6, 3, 7, 6]
n, m = map(int, input().split())
alist = list(map(int, input().split()))
alist.sort(reverse = True)

dp = [-1 for _ in range(n+1)]
dp[0] = 0
for a in alist:
    match = matches[a]
    for i in range(n - match + 1):
        if dp[i] == -1:
            continue
        dp[i + match] = max(dp[i+match], dp[i] * 10 + a)
        
print(dp[-1])