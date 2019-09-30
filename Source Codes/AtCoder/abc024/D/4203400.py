MOD = 10**9+7


def solve(A, B, C):
    r = B * C % MOD - A * C % MOD
    r = r * pow(A*B%MOD+A*C%MOD-B*C%MOD, MOD-2, MOD) % MOD

    c = C * B % MOD - A * B % MOD
    c = c * pow(A*C%MOD+A*B%MOD-B*C%MOD, MOD-2, MOD) % MOD

    return r, c


def main():
    A=int(input())
    B=int(input())
    C=int(input())
    r, c = solve(A, B, C)
    print(r, c)


if __name__ == '__main__':
    main()