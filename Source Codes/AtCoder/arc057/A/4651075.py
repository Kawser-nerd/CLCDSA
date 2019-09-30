A, K = map(int, input().split())
X = 2 * 10**12
ans = 0
if K == 0:
    ans = X - A
else:
    while A < X:
        A += 1 + K * A
        ans += 1
print(ans)