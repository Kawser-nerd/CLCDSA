import sys

def solve():
    a = int(input())
    b = int(input())

    if a == b:
        print(1)
        return

    t = a ^ b
    N = bitlen(t)

    a = a & (2**N - 1)
    b = b & (2**N - 1)

    blen = bitlen(b)

    sb = b & (2**(blen - 1) - 1)

    sblen = bitlen(sb)

    s = 2**sblen - 1

    ymax = b | s

    T = 2**(N - 1)

    ans = T - a

    if ymax < T + a:
        ans += ymax + 1 - a
    else:
        ans += T

    print(ans)

def bitlen(x):
    return 1 + bitlen(x >> 1) if x else 0

if __name__ == '__main__':
    solve()