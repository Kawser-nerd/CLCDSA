A = int(input())
B = int(input())
C = int(input())

mod = 10**9 + 7

def pow(x, n):
    if n == 1: return x
    d, m = divmod(n, 2)
    p = pow(x, d)
    return (p * p * (x if m == 1 else 1)) % mod

c = ((B*C - A*B) * pow(A*C - B*C + A*B, mod - 2)) % mod
r = ((B*C - A*C) * pow(A*B - B*C + A*C, mod - 2)) % mod
print(r, c)