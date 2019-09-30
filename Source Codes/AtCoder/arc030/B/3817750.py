N, X = map(int, input().split(" "))
H = list(map(int, input().split(" ")))
AB = [list(map(int, input().split(" "))) for _ in range(N-1)]

s = [set() for _ in range(N+1)]
for a, b in AB:
    s[a].add(b)
    s[b].add(a)

def dfs(n, before=None):
    # print(n, s[n], {before})
    routes = s[n] - {before}
    # if len(routes) == 0:
    #     return H[n-1]*2
    m = 0
    for route in routes:
        l = dfs(route, n)
        if l != 0 or H[route-1]:
            m += l+2
    # print(m)
    return m


print(dfs(X))