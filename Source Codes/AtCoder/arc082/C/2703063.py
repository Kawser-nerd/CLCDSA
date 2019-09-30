# seishin.py
N = int(input())
P = [list(map(int, input().split())) for i in range(N)]

MOD = 998244353

ans = pow(2, N, MOD) - 1 - N
u = set()
for i in range(N):
    xi, yi = P[i]
    for j in range(i+1, N):
        xj, yj = P[j]
        if (i, j) in u:
            continue
        cnt = 0
        Q = {i, j}
        for k in range(N):
            xk, yk = P[k]
            if (xj - xi)*(yk - yi) == (xk - xi)*(yj - yi):
                cnt += 1
                Q.add(k)
        for p in Q:
            for q in Q:
                u.add((p, q))
        ans -= pow(2, cnt, MOD) - cnt - 1
print(ans % MOD)