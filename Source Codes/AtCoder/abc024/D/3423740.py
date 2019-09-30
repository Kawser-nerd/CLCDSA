A = int(input())
B = int(input())
C = int(input())

MOD = 1000000007

def mod_pow(x, n):
    if n == 0:
        return 1
    res = mod_pow(x * x %MOD, n // 2)
    if n & 1:
        return res * x %MOD
    else:
        return res %MOD

# x = (BC - AB) / (AB - BC + CA)
# y = (BC - CA) / (AB - BC + CA)
x = (B * C %MOD - A * B %MOD) %MOD
y = (B * C %MOD - C * A %MOD) %MOD
z = ((A * B %MOD - B * C %MOD) %MOD + C * A %MOD) %MOD
inv_z = mod_pow(z, MOD - 2)

print(y * inv_z %MOD, x * inv_z %MOD)