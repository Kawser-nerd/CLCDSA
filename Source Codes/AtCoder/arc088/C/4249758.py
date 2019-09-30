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

a = ord('a')

def make_index(s):

    index = [[] for _ in range(26)]
    for i, ch in enumerate(s):
        index[ord(ch) - a].append(i)

    return index

def solve(s):

    n = len(s)
    index = make_index(s)

    odd = None
    for code, char_pos in enumerate(index):
        if len(char_pos) % 2 == 1:
            if odd is not None:
                return -1
            odd = code

    bit = Bit(n)

    ans = 0
    cnt = 0
    for i in range(n):
        if bit.sum(i + 1) - bit.sum(i) == 1:
            continue
        code = ord(s[i]) - a
        if code == odd and index[code][-1] == i:
            continue
        cnt += 1
        j = index[code].pop()
        ans += n - cnt - (j - bit.sum(j))
        bit.add(j, 1)
        if n // 2 <= cnt:
            break

    if odd is not None:
        j = index[odd][-1]
        ans += abs(n // 2 - (j - bit.sum(j)))

    return ans


def main():
    s = input()

    print(solve(s))


if __name__ == '__main__':
    main()