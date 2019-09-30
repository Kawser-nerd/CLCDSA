# coding:utf-8


INF = float('inf')


def inpl(): return list(map(int, input().split()))


N, X = inpl()
A = inpl()
B = [0]
for a in A:
    B.append(B[-1] + a)

ans = INF
for k in range(1, N + 1):
    tmp = 5 * B[N] + (N + k) * X
    cur = N - 2 * k
    while cur > 0:
        tmp += 2 * B[cur]
        cur -= k
    ans = min(ans, tmp)
print(ans)