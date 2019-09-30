#!/usr/bin/env python3


def solve(N, X, g):

    visited = [0] * N
    d = {}

    st = [(0, 0)]
    while len(st):
        v, r = st.pop()
        visited[v] = 1
        if r in d:
            d[r] += 1
        else:
            d[r] = 1
        for tpl in g[v]:
            w, c = tpl
            if not visited[w]:
                st.append((w, r ^ c))


    ans = 0
    for a, na in d.items():
        b = a ^ X
        if b == a:
            ans += na * (na - 1)
        elif b in d:
            ans += na * d[b]
    ans = ans // 2
    return ans


def main():
    N, X = input().split()
    N = int(N)
    X = int(X)
    g = [[] for _ in range(N)]
    for _ in range(N - 1):
        x, y, c = input().split()
        x = int(x) - 1
        y = int(y) - 1
        c = int(c)
        g[x].append((y, c))
        g[y].append((x, c))


    print(solve(N, X, g))


if __name__ == '__main__':
    main()