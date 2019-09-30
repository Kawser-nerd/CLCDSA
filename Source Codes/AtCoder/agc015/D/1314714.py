import sys

def solve():
    a = int(input())
    b = int(input())

    if a == b:
        print(1)
        return

    t = a ^ b
    N = len(bin(t)) - 2
    t = 1 << N

    a = a & (t - 1)
    b = b & (t - 1)

    blen = len(bin(b)) - 2

    sb = b & (2**(blen - 1) - 1)

    if sb == 0:
        sblen = 0
    else:
        sblen = len(bin(sb)) - 2

    s = (1<<sblen) - 1

    ymax = b | s

    T = 1<<(N - 1)

    ans = T - a

    if ymax < T + a:
        ans += ymax - T + 1 + T - a
    else:
        ans += T

    print(ans)


if __name__ == '__main__':
    solve()