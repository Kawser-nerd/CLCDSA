from collections import deque
from functools import reduce
from itertools import zip_longest
from operator import mul


def dfs(links):
    q = deque([(v, 0) for v in links[0]])
    v = 0
    while q:
        v, a = q.popleft()
        q.extend((u, v) for u in links[v] if u != a)

    anc = [-1] * len(links)
    q = deque([(u, v) for u in links[v]])
    u = 0, 0
    while q:
        u, a = q.popleft()
        anc[u] = a
        q.extend((w, u) for w in links[u] if w != a)

    path = [u]
    a = u
    while a != v:
        a = anc[a]
        path.append(a)
    return path


def calc(links, v, a, l):
    ans = [1] * l
    q = deque([(u, v, 1) for u in links[v] if u != a])
    ans[0] = len(q)
    while q:
        u, a, c = q.popleft()
        ans[c] = max(ans[c], len(links[u]) - 1)
        q.extend((w, u, c + 1) for w in links[u] if w != a)
    return ans


def solve(n, links):
    if n == 2:
        return 1, 2

    path = dfs(links)
    c = len(path)
    l = (len(path) + 1) // 2
    # print('path', path)

    if c % 2 == 0:
        u, v = path[c // 2 - 1], path[c // 2]
        ans1 = calc(links, u, v, l)
        ans2 = calc(links, v, u, l)
        # print('ans12', ans1, ans2)
        leaves = 1
        for a1, a2 in zip(ans1, ans2):
            leaves *= max(a1, a2)
        return len(ans1), leaves * 2
    v = path[c // 2]
    ans0 = calc(links, v, None, l)
    leaves = reduce(mul, ans0, 1)
    # print('ans0', ans0, leaves)
    for u in links[v]:
        ans1 = calc(links, u, v, l)
        ans2 = calc(links, v, u, l)
        tmp = 1
        for a1, a2 in zip_longest(ans1, ans2):
            tmp *= max(a1, a2)
        # print('ans12', ans1, ans2, tmp)
        leaves = min(leaves, tmp * 2)
    return len(ans0), leaves


n = int(input())
links = [set() for _ in range(n)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    links[a].add(b)
    links[b].add(a)
print(*solve(n, links))