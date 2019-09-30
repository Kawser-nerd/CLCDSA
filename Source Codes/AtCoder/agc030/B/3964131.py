import math

L, N = (int(i) for i in input().split())
X = [int(input()) for _ in range(N)]
X.insert(0, 0)

X_r = [L - i for i in reversed(X)]
X_r.insert(0, 0)
X_r.pop()

def lsum(l):
    s = 0
    for i in l:
        s += i
        yield s

X_sum = list(lsum(X))
X_r_sum = list(lsum(X_r))

def f_l(p, n):
    N_tmp = N - n
    a = N_tmp // 2
    if N_tmp == 0:
        return 0
    elif N_tmp % 2 == 0:
        return 2 * X_sum[a] + X_r_sum[a + n] + X_r_sum[a + n - 1] - 2 * X_r_sum[n] + p
    else:
        return X_sum[a+1] + X_sum[a] + 2 * X_r_sum[a + n] - 2 * X_r_sum[n] + p


def f_r(p, n):
    N_tmp = N - n
    a = N_tmp // 2
    if N_tmp == 0:
        return 0
    elif N_tmp % 2 == 0:
        return 2 * X_r_sum[a] + X_sum[a + n] + X_sum[a + n - 1] - 2 * X_sum[n] + p
    else:
        return X_r_sum[a+1] + X_r_sum[a] + 2 * X_sum[a + n] - 2 * X_sum[n] + p

max_l = max(X[i] + f_r(X[i], i) for i in range(1, N+1))
max_r = max(X_r[i] + f_l(X_r[i], i) for i in range(1, N+1))

print(max(max_l, max_r))