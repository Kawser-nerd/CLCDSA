def d_takahashi_ball_first(A, B, C):
    import math
    from scipy.optimize import newton

    def g(t):
        return A * t + B * math.sin(C * math.pi * t) - 100

    def dg(t):
        return A + B * C * math.pi * math.cos(C * math.pi * t)

    # g(t) ???????????Newton-Raphson????????
    ans = newton(g, 100 / A, fprime=dg)
    return ans

A, B, C = [int(i) for i in input().split()]
print(d_takahashi_ball_first(A, B, C))