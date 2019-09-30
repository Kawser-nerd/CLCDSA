N = int(input())
F = [list(map(int, input().split())) for i in range(N)]
P = [list(map(int, input().split())) for i in range(N)]

ans = -10 ** 10
for b in range(1, 2 ** 10):
    bin_str = format(b, '010b')
    p = 0
    for i in range(N):
        c = 0
        for j in range(10):
            c += F[i][j] * int(bin_str[j])
        p += P[i][c]
    ans = max(ans, p)
print(ans)