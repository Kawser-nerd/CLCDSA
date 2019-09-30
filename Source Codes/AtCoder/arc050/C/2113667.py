A, B, M = map(int, input().split())

def gcd(m, n):
    r = m % n
    return gcd(n, r) if r else n
G = gcd(A, B)

def mul(A, B):
    a, b, c, d = A; p, q, r, s = B
    return (a*p + b*r) % M, (a*q + b*s) % M, (c*p + d*r) % M, (c*q + d*s) % M

def m_pow(x, n):
    S = pow(10, x, M), 1, 0, 1
    R = 1, 0, 0, 1
    while n:
        if n & 1:
            R = mul(R, S)
        S = mul(S, S)
        n >>= 1
    return R[1]

P = m_pow(G, A//G)
Q = m_pow(1, B)
print((P * Q) % M)