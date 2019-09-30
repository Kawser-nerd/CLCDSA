from operator import mul

n, m = map(int, input().split())
xs = list(map(int, input().split()))
ys = list(map(int, input().split()))

MOD = 10 ** 9 + 7

fX = sum(map(mul, xs, range(-n + 1, n + 1, 2))) % MOD
fY = sum(map(mul, ys, range(-m + 1, m + 1, 2))) % MOD

print((fX * fY) % MOD)