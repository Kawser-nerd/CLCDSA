H, W, A, B = map(int, input().split())
P = 10 ** 9 + 7
N = H + W

# nCr mod P (P ???) ? 1 <= r <= n <= N ????????????????
# fact ? n! mod P (n=0,...,N) ???????
# inv_fact ? n!^(-1) mod P (n=0,...,N) ???????
def fact(N, P):
    ret = [1] * (N + 1)
    for n in range(2, N+1):
        ret[n] = (ret[n-1] * n) % P

    return ret


# ???????? a ** b mod P ???
def pow_r(a, b, P):
    """
    O(log n)
    """
    if b == 0:  # exit case
        return 1
    if b % 2 == 0:  # standard case ? n is even
        return pow_r((a ** 2) % P, b // 2, P)
    else:  # standard case ? n is odd
        return (a * pow_r((a ** 2) % P, (b - 1) // 2, P)) % P


def inv_fact(N, P):
    ret = [1] * (N + 1)
    fac = fact(N, P)
    ret[N] = pow_r(fac[N], P - 2, P)
    for n in reversed(range(2, N)):
        ret[n] = (ret[n + 1] * (n + 1)) % P

    return ret


fac = fact(N, P)
inv = inv_fact(N, P)
# nCr mod P (P ???) ? 1 <= r <= n <= N ?????????
def combination(n, r, P):
    return (fac[n] * inv[r] * inv[n - r]) % P



sub = 0
for a in range(A):
    sub = (sub + combination((H - 1 - a) + (B - 1), B - 1, P) * combination(a + (W - 1 - B), a, P)) % P

print((combination((H - 1) + (W - 1), H - 1, P) - sub) % P)