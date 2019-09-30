import sys


def solve(n, m, links):
    v4 = set()
    v6 = 0
    for v, link in enumerate(links):
        l = len(link)
        if l % 2 == 1:
            return False
        if l == 4:
            v4.add(v)
        elif l >= 6:
            v6 += 1
    if v6 > 0:
        return True
    if len(v4) > 2:
        return True
    if len(v4) < 2:
        return False
    s = v4.pop()
    t = v4.pop()
    for c in links[s]:
        visited = {s, t}
        q = [c]
        while q:
            v = q.pop()
            if v in visited:
                continue
            visited.add(v)
            for u in links[v]:
                if v != c and u == s:
                    return True
                if u not in visited:
                    q.append(u)
    return False


n, m = map(int, input().split())
links = [set() for _ in [0] * n]
for line in sys.stdin:
    a, b = map(int, line.split())
    a -= 1
    b -= 1
    links[a].add(b)
    links[b].add(a)
print('Yes' if solve(n, m, links) else 'No')