n = int(input())
k = int(input())
x = list(map(int, input().split()))
ans = 0
for i in range(n):
    if x[i] >= k:
        ans += 2 * (x[i] - k)
    else:
        ans += 2 * min(x[i], k - x[i])
print(ans)