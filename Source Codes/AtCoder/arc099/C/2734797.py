def dfs(links, fixed, s):
    q = [(s, 0)]
    cnt = [0, 0]
    while q:
        v, c = q.pop()
        if fixed[v] > -1:
            if fixed[v] != c:
                return False
            continue
        fixed[v] = c
        cnt[c] += 1
        for u in links[v]:
            q.append((u, c ^ 1))
    return (max(cnt), min(cnt))


def is_bipartite(n, links):
    fixed = [-1] * n
    l, r = 0, 0
    can = []
    for i in range(n):
        if fixed[i] > -1:
            continue
        cnt = dfs(links, fixed, i)
        if cnt == False:
            return -1
        can.append(cnt)

    can.sort(reverse=True)
    for cnt in can:
        j = 0 if cnt[0] > cnt[1] else 1
        if l > r:
            j ^= 1
        l += cnt[j]
        r += cnt[j ^ 1]
    return (l * (l - 1) + r * (r - 1)) // 2


n, m = map(int, input().split())
links = [set(range(n)) - {i} for i in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    links[a].remove(b)
    links[b].remove(a)
print(is_bipartite(n, links))