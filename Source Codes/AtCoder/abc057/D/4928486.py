import sys
from collections import Counter
try:
    from scipy.special import comb
except ImportError:
    from scipy.misc import comb

def main():
    input = sys.stdin.readline
    N, A, B = map(int, input().split())
    V = list(map(int, input().split()))
    V = sorted(V, key=lambda x: -x)

    m_ave = sum(V[:A]) / A
    b = A
    while b < B:
        if V[0] == V[b]:
            b += 1
        else:
            break

    if A == b:
        ans = 1
        c = Counter(V[:A])
        d = Counter(V)
        for key in c.keys():
            n = d[key]
            r = c[key]
            ans *= comb(n, r, exact=True)

    else:
        d = Counter(V)
        key = V[0]
        n = d[key]
        ans = 0
        for r in range(A, b+1):
            ans += comb(n, r, exact=True)

    print(m_ave)
    print(ans)


if __name__ == '__main__':
    main()