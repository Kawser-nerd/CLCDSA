from collections import defaultdict

MAX = 40001


def main():
    N, Ma, Mb = [int(a) for a in input().split()]

    abc = [
        [int(a) for a in input().split()]
        for _ in range(N)
    ]

    dp = [
        [
            [MAX for b in range(10 * N + 1)]
            for a in range(10 * N + 1)
        ]
        for i in range(N)
    ]  # dp[i][a][b] = i????????a???b???????????

    A, B, C = abc[0]
    # dp[0][a][b] = c
    # dp[0][0][0] = 0

    mem = {(0, A, B): C, (0, 0, 0): 0}

    def solve(i, a, b):
        if (i, a, b) in mem:
            return mem[(i, a, b)]
        if i == 0:
            return MAX
        ai, bi, ci = abc[i]
        tukawanai = solve(i - 1, a, b)
        if a - ai >= 0 and b - bi >= 0:
            pre = solve(i - 1, a - ai, b - bi)
            if pre != MAX:
                mem[(i, a, b)] = min(tukawanai, pre + ci)
                return mem[(i, a, b)]
        mem[(i, a, b)] = tukawanai
        return mem[(i, a, b)]

    res = MAX
    for a in range(1, 10 * N + 1):
        aa = a * Mb
        if aa % Ma != 0:
            continue
        b = aa // Ma
        if b >= 10 * N + 1:
            continue
        c = solve(N - 1, a, b)
        res = min(res, c)

    if res == MAX:
        res = -1
    print(res)


if __name__ == '__main__':
    main()