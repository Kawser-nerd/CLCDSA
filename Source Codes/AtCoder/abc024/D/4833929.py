a, b, c = int(input()), int(input()), int(input())
mod = 10 ** 9 + 7
inv = pow((b + c) * a - b * c, mod - 2, mod)
print((b - a) * c * inv % mod, (c - a) * b * inv % mod)