from itertools import accumulate
from bisect import bisect_right

N, K = map(int, input().split())
A = [int(input()) for i in range(N)]

diff = [a - K for a in A]
diff = [0] + list(accumulate(diff))


class BinaryIndexedTree:
    def __init__(self, n):
        self.size = n
        self.bit = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= (i & -i)
        return s

    def add(self, i, x):
        while i <= self.size:
            self.bit[i] += x
            i += (i & -i)

    def reset(self):
        self.bit = [0] * (self.size + 1)


BIT = BinaryIndexedTree(N + 1)

temp = sorted(diff)
order = [bisect_right(temp, d) for d in diff]
ans = 0

for x in order:
    ans += BIT.sum(x)
    BIT.add(x, 1)

print(ans)