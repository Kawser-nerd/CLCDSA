def baibai_chance(N: int) -> str:
    depth = 0
    n = N
    while 1 < n:
        depth += 1
        n >>= 1

    def m2(x): return x << 1
    def m2p1(x): return (x << 1) + 1

    if depth % 2 == 0:
        Tst, Ast = m2p1, m2
    else:
        Tst, Ast = m2, m2p1

    x = 1
    while True:
        # Takahashi ???
        x = Tst(x)
        if N < x:
            return "Aoki"

        # Aoki ???
        x = Ast(x)
        if N < x:
            return 'Takahashi'


if __name__ == "__main__":
    N = int(input())
    ans = baibai_chance(N)
    print(ans)