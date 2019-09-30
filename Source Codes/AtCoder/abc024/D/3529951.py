A = int(input())
B = int(input())
C = int(input())

def egcd(a, b):
    (x, lastx) = (0, 1)
    (y, lasty) = (1, 0)
    while b != 0:
        q = a // b
        (a, b) = (b, a % b)
        (x, lastx) = (lastx - q * x, x)
        (y, lasty) = (lasty - q * y, y)
    return (lastx, lasty, a)

# ax ? 1 (mod m)
def modinv(a, m):
    (inv, q, gcd_val) = egcd(a, m)
    return inv % m

m = 10**9+7
inv = modinv((B+C)*A-B*C,m)
r = (B-A)*C*inv%m
c = (C-A)*B*inv%m

print('{} {}'.format(r,c))