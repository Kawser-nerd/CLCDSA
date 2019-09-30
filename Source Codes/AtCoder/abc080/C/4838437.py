N = int(input())
F = [list(map(int, input().split())) for _ in range(N)]
P = [list(map(int, input().split())) for _ in range(N)]
ans = -float('inf')
for i in range(1, 2 ** 10):
    t = 0
    for j in range(N):
        c = 0
        for k in range(10):
            c += ((i >> k) & 1) & F[j][k]
        t += P[j][c]
    ans = max(ans, t)
print(ans)