# coding: utf-8

II = lambda: int(input())
MI = lambda: map(int, input().split())


def main():
    N = II()
    A, B, C = sorted(list(MI())), sorted(list(MI())), sorted(list(MI()))

    s = [i for i in range(1, N + 1)]
    ia = N-1
    ns = [None] * N
    for ib in range(N-1, -1, -1):
        while ia >= 0 and A[ia] >= B[ib]:
            ia -= 1
        if ia >= 0:
            ns[ib] = s[ia]
        else:
            ns[ib] = 0
    for i in range(1, N):
        ns[i] += ns[i-1]

    s = ns
    ib = N-1
    ns = [None] * N
    for ic in range(N-1, -1, -1):
        while ib >= 0 and B[ib] >= C[ic]:
            ib -= 1
        if ib >= 0:
            ns[ic] = s[ib]
        else:
            ns[ic] = 0
    return sum(ns)


if __name__ == "__main__":
    print(main())