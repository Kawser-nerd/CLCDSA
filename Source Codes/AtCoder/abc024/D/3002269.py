A = int(input())
B = int(input())
C = int(input())

mod = 10 ** 9 + 7
c = ((B * C - A * B) * pow(A * C - B * C + A * B, mod - 2, mod)) % mod
r = (((B - A) * c - A + B) * pow(A, mod - 2, mod)) % mod

print(r, c)