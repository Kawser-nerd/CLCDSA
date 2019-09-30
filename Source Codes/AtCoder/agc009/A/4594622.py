N = int(input())
a, b = [], []
for _ in range(N):
    aa, bb = map(int, input().split())
    a.append(aa)
    b.append(bb)

ans = 0
add_v = 0
i = N - 1
while i >= 0:
    r = (a[i] + add_v) % b[i]
    if r != 0:
        to_add = b[i] - r
        add_v += to_add
        ans += to_add
    i -= 1
print(ans)