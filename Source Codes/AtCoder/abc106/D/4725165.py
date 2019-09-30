N, M, Q = map(int, input().split())
sum_v = [ [0] * 505 for _ in range(505) ]

for _ in range(M):
    l, r = map(int, input().split())
    sum_v[l][r] += 1

for i in range(1, N+1):
    for j in range(1, N+1):
        sum_v[i][j] += sum_v[i-1][j]
        sum_v[i][j] += sum_v[i][j-1]
        sum_v[i][j] -= sum_v[i-1][j-1]

for _ in range(Q):
    p, q = map(int, input().split())

    ans  = sum_v[q][q]
    ans -= sum_v[q][p-1]
    ans -= sum_v[p-1][q]
    ans += sum_v[p-1][p-1]

    print(ans)