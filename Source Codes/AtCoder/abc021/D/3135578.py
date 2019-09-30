def get_inverse_element(x: int, mod: int) -> int:
    ans = 1
    bit = bin(mod-2)[:1:-1]
    for c in bit:
        if c == "1":
            ans = ans * x % mod
        x = x * x % mod
    return ans

n, k, mod = int(input()), int(input()), 10**9+7
n1, n2, n3 = 1, 1, 1
_n = 1
for i in range(1, n+k):
    _n = (_n*i)%mod
    if i == n-1+k:
        n1 = _n
    if i == n-1:
        n2 = _n
    if i == k:
        n3 = _n

n2 = get_inverse_element(n2, mod)
n3 = get_inverse_element(n3, mod)
print((n1*n2*n3)%mod)