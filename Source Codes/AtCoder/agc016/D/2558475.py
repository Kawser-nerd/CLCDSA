from collections import defaultdict
from functools import reduce
from operator import xor


def dfs(s, links, fixed):
    q = [s]
    while q:
        v = q.pop()
        if fixed[v]:
            continue
        fixed[v] = True
        q.extend(links[v])


def solve(n, aaa, bbb):
    a0 = reduce(xor, aaa, 0)
    b0 = reduce(xor, bbb, 0)
    aaa.append(a0)
    bbb.append(b0)
    ad = defaultdict(set)
    bd = defaultdict(set)
    for i, a in enumerate(aaa):
        ad[a].add(i)
    for i, b in enumerate(bbb):
        bd[b].add(i)
    ac = {a: len(s) for a, s in ad.items()}
    bc = {b: len(s) for b, s in bd.items()}
    if ac != bc:
        return -1
    links = defaultdict(set)
    ans = 0
    for a, b in zip(aaa, bbb):
        if a == b:
            continue
        ans += 1
        links[a].add(b)

    if not ans:
        return 0

    if a0 == b0:
        links[a0].add(b0)
    else:
        ans -= 1

    fixed = {a: False for a in links}
    for a in links:
        if fixed[a]:
            continue
        ans += 1
        dfs(a, links, fixed)

    return ans - 1


n = int(input())
aaa = list(map(int, input().split()))
bbb = list(map(int, input().split()))
print(solve(n, aaa, bbb))