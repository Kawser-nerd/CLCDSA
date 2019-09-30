from collections import deque


def first_cut(links, colors):
    tmp_links = links.copy()
    for v, neighbors in tmp_links.items():
        while len(neighbors) == 1 and colors[v]:
            del links[v]
            par = neighbors.pop()
            links[par].remove(v)
            v = par
            neighbors = links[par]
    return links


def diameter(links, flags):
    def dfs(s):
        fs = flags[s]
        d, v = 0, 0
        q = deque(sorted((fs + flags[v], v, s) for v in links[s]))
        while q:
            d, v, a = q.popleft()
            for u in links[v]:
                if u == a:
                    continue
                fu = flags[u]
                if fu:
                    q.append((d + 1, u, v))
                else:
                    q.appendleft((d, u, v))
        return d, v

    s = next(iter(links))
    _, t = dfs(s)
    d, _ = dfs(t)
    return d


def solve(links, colors):
    if all(colors):
        return 0

    links = first_cut(links, colors)
    k = len(links)

    if k == 1:
        return 1

    flags = {v: colors[v] ^ (len(link) % 2 == 0) for v, link in links.items()}
    euler_tour = 2 * (k - 1) + sum(flags.values())
    return euler_tour - 2 * diameter(links, flags)


n = int(input())
links = {i: set() for i in range(n)}
for _ in range(n - 1):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    links[x].add(y)
    links[y].add(x)
colors = [c == 'B' for c in input()]

print(solve(links, colors))