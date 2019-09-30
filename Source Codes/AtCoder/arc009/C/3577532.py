def get_inverse_element(x: int, mod: int = 10**9+7) -> int:
    ans = 1
    for c in bin(mod-2)[:1:-1]:
        if c == "1":
            ans = ans * x % mod
        x = x * x % mod
    return ans


if __name__ == "__main__":
    N, K = map(int, input().split())
    mod = 1777777777

    n1, n2 = 1, 1
    for x in range(N, N-K, -1):
        n1 = n1 * x % mod
    for x in range(K, 1, -1):
        n2 = n2 * x % mod
    n1 = n1 * get_inverse_element(n2, mod) % mod

    m1, m2 = 1, 0
    for i in range(3, K+1):
        m1, m2 = (i-1)*(m1+m2) % mod, m1
    print(n1 * m1 % mod)