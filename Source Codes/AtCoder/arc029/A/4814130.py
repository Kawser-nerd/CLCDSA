from itertools import product
ans = 10**9
N = int(input())
m = [int(input()) for _ in range(N)]
for i in range(1 << N):
    a, b = 0, 0
    for j in range(N):
        if ((i >> j) & 1) == 0:
            a += m[j]
        else:
            b += m[j]
    ans = min(ans, max(a, b))
print(ans)