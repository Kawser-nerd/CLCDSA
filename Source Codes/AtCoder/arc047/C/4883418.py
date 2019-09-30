#!/usr/bin/env python3


class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * n

    def sum(self, i):
        s = 0
        i -= 1
        while i >= 0:
            s += self.tree[i]
            i = (i & (i + 1)) - 1
        return s

    def add(self, i, x):
        while i < self.size:
            self.tree[i] += x
            i |= i + 1


def solve(n, k):

    bit = Bit(n)
    arr = [0] * n

    q = 1
    for i in range(n):
        q *= n - i
        p = q // k
        q %= k
        if q == 0:
            p -= 1
        lo = -1
        hi = n
        while lo + 1 < hi:
            mid = (lo + hi + 1) // 2
            r = mid - bit.sum(mid + 1)
            if p < r:
                hi = mid
            else:
                lo = mid
        print(hi)
        bit.add(hi, 1)
        arr[hi - 1] = 1
        if q == 0:
            for j in range(n - 1, -1, -1):
                if arr[j] == 0:
                    print(j + 1)
            break



def main():
    n, k = input().split()
    n = int(n)
    k = int(k)


    solve(n, k)

if __name__ == '__main__':
    main()