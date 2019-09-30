# coding:utf-8


INF = float('inf')


def inpl(): return list(map(int, input().split()))


N, X = inpl()
A = inpl()
B = [0]
for a in A:
    B.append(B[-1] + a)

ans = []
for k in range(1, N + 1):
    e = 5
    cur = N - k
    tmp = e * (B[N] - B[cur]) + (N + k) * X
    cur -= k
    while True:
        tmp += e * (B[cur + k] - B[max(cur, 0)])
        if cur <= 0:
            break
        e += 2
        cur -= k

    ans.append(tmp)

print(min(ans))