import math


def takahashi_ball1(A: int, B: int, C: int) -> float:
    E = 10 ** (-6)

    def f(t: float) -> float:
        return A * t + B * math.sin(C * t * math.pi)

    def newton(ta: float, tb: float, g) -> float:
        if g(tb) < 0:
            # ???? ta ????
            ta, tb = tb, ta

        while True:
            m = (ta + tb) / 2
            if abs(g(m)) < E:
                return m
            if g(m) < 0:
                ta = m
            else:
                tb = m

    ta = 0
    k = 0
    while True:
        tb = ta
        ta = (2 * k + 1) // (2 * C)

        if (f(tb) - 100) * (f(ta) - 100) < 0:
            # ??????
            return newton(ta, tb, lambda x: f(x) - 100)
        elif (f(tb) - 100) * (f(ta) - 100) <= E * E:
            # ????? 0 ??????
            if abs(f(tb) - 100) <= E:
                return tb
            if abs(f(ta) - 100) <= E:
                return ta
        else:
            k += 1


if __name__ == "__main__":
    A, B, C = map(int, input().split())
    ans = takahashi_ball1(A, B, C)
    print(ans)