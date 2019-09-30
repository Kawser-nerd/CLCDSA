N, K = map(int, open(0).read().split())
ans = 1
for i in range(N):
    if ans < K:
        ans = ans << 1
    else:
        ans += K
print(ans)