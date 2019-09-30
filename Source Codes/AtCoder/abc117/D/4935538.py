N, k = map(int, input().split())
d = {i: 0 for i in range(40)}
for n in map(int, input().split()):
    for j in range(40):
        if (n >> j) & 1:
            d[j] += 1
ans = 0
num = 0
for i in range(39, -1, -1):
    if num + 2 ** i <= k:
        if N - 2 * d[i] < 0:
            ans += 2 ** i * d[i]
        else:
            ans += 2 ** i * (N - d[i])
            num += 2 ** i
    else:
        ans += 2 ** i * d[i]
print(ans)