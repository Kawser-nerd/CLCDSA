n, x = map(int, input().split())
a = list(map(int, input().split()))

# ????????????
DP = a[:]
ans = sum(DP)
for i in range(n-1):
    DP = [min(DP[j],DP[j-1]) for j in range(n)]
    ans = min(ans, sum(DP) + (i+1)*x)
print(ans)