from string import ascii_lowercase


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


def solve(s):
    indices = {c: [] for c in ascii_lowercase}
    for i, c in enumerate(s):
        indices[c].append(i)

    n = len(s)
    center = n // 2
    bubbles = [-1] * n
    odd_flag = False
    lefts, rights = [], []
    for c, ids in indices.items():
        cnt = len(ids)
        if cnt & 1:
            if odd_flag:
                return -1
            odd_flag = True
            bubbles[ids[cnt // 2]] = center + 1
        for i in range(cnt // 2):
            li, ri = ids[i], ids[-i - 1]
            if li < center:
                lefts.append((li, ri))
            else:
                rights.append((li, ri))
    lefts.sort()
    rights.sort()
    r_itr = iter(rights)
    for i, (li, ri) in enumerate(lefts):
        bubbles[li] = i + 1
        bubbles[ri] = n - i
    for i in range(len(lefts), center):
        li, ri = next(r_itr)
        bubbles[li] = i + 1
        bubbles[ri] = n - i

    ans = 0
    bit = Bit(n)
    for i, m in enumerate(bubbles):
        ans += i - bit.sum(m)
        bit.add(m, 1)
    return ans


print(solve(input()))