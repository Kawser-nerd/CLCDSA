n, m = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
mod = 10 ** 9 + 7
ans = 0
def f(a, n):
    ret = 0
    for i, v in enumerate(a):
        ret += i * v - (n - i - 1) * v
        ret %= mod
    return ret
print((f(x, n) * f(y, m)) % mod)