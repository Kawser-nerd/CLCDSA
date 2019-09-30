N, M = map(int, input().split())
A = [list(map(int, input().split())) for i in range(N)]

ans = N
for i in range(M - 1):
    p = [0] * M
    for j in range(N):
        p[A[j][0] - 1] += 1
    mp = max(p)
    MM = p.index(mp) + 1
    ans = min(ans, mp)
    for j in range(N):
        A[j].remove(MM)

print(ans)