import sys
from itertools import accumulate

def solve():
    n, k = map(int, sys.stdin.readline().split())
    a = [int(sys.stdin.readline().rstrip()) - k for i in range(n)]
    s = [0] + list(accumulate(a))

    # ????
    s = [(si, i) for (i, si) in enumerate(s)]
    s.sort()

    z = [None] * (n + 1)

    num = -1
    p = -float('inf')

    for i in range(n + 1):
        if s[i][0] > p:
            num += 1

        z[s[i][1]] = num
        p = s[i][0]

    # FenwickTree????????
    ft = FenwickTree(num + 1)

    ans = 0

    for zi in z:
        ans += ft.psum(zi + 1)
        ft.add(zi, 1)

    print(ans)

class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.b = [0] * (n + 1)

    def add(self, i, x):
        i += 1

        while i <= self.n:
            self.b[i] += x
            i += i & (-i)

    def psum(self, r):
        res = 0

        while r > 0:
            res += self.b[r]
            r -= r & (-r)

        return res

if __name__ == '__main__':
    solve()