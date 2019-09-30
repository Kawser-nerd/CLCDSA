N = int(input())
a = list(map(int, input().split()))
b = [0] * (N + 1)
for i in range(N):
    b[a[i]] = i + 1
l = [i for i in range(N + 2)]
r = [i for i in range(N + 2)]
ans = 0
for i in range(N, 0, -1):
    m = b[i]
    x = l[m]
    y = r[m]
    ans += (m - x + 1) * (y - m + 1) * i
    r[x - 1] = y
    l[y + 1] = x
print(ans)