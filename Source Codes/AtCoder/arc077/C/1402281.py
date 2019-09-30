from collections import defaultdict


class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i


n, m = map(int, input().split())
aa = list(map(int, input().split()))
counter = defaultdict(list)

bit = Bit(m + 1)
ans_1 = 0
for a, b in zip(aa, aa[1:]):
    counter[b].append(a)
    bit.add(a + 1, 1)
    bit.add(b, -1)
    if a > b:
        bit.add(1, 1)
        ans_1 += b
    else:
        ans_1 += b - a

ans_prev = ans_1
ans_min = ans_1
for x in range(2, m + 1):
    ans_x = ans_prev
    px = x - 1
    if px in counter:
        ans_x += sum((px - a) % m - 1 for a in counter[px])
    ans_x -= bit.sum(px)
    ans_min = min(ans_min, ans_x)
    ans_prev = ans_x
print(ans_min)