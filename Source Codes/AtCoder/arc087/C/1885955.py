from collections import defaultdict


def solve(l, ss):
    xor = 0
    for d in range(min(ss), l + 1):
        sl = ss[d]
        sl.sort()
        while sl:
            s = sl.pop()
            ps = s[:-1]
            ss[d + 1].append(ps)
            if s[-1] == '1' and sl and sl[-1][:-1] == ps:
                sl.pop()
            else:
                xor ^= d & -d
        del ss[d]
    return xor


n, l = map(int, input().split())
ss = defaultdict(list)
for s in (input() for _ in range(n)):
    ss[l - len(s) + 1].append(s)

print('Alice' if solve(l, ss) else 'Bob')