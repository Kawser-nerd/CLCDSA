import sys


def df(N: int) -> int:
    y = 0
    while N > 0:
        y += N % 10
        N //= 10
    return y


def func(N: int) -> int:
    min_val, min_t = N / df(N), N
    d = 0
    while N > 0:
        N //= 10
        d = d * 10 + 9
        NN = N * (d + 1) + d
        val = NN / df(NN)
        if min_val > val:
            min_val = val
            min_t = NN
    return min_t


N = int(sys.stdin.readline())
z = 0
for _ in range(N):
    z = func(z + 1)
    print(z)