import sys

def doubling(n, x, mod):
    ans, exponent = 0, len(str(n))
    while x:
        if x & 1:
            ans = (ans * pow(10, exponent, mod) + n) % mod
        n = (n * pow(10, exponent, mod) + n) % mod
        exponent *= 2
        x >>= 1
    return ans


if __name__ == "__main__":
    N = int(input())
    a = [list(map(int, sys.stdin.readline().split())) for _ in [0]*N]
    mod = int(input())
    ans = 0

    for n, repeat in a:
        ans = (ans * pow(10**len(str(n)), repeat, mod) + doubling(n, repeat, mod)) % mod

    print(ans)