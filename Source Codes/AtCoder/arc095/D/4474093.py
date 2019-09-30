#!/usr/bin/env python3


def solve(n, adj_list, d):

    s = []
    path_adj_list = [[] for _ in range(n)]
    for v in range(n):
        if 1 < d[v]:
            p = path_adj_list[v]
            for w in adj_list[v]:
                if 1 < d[w]:
                    p.append(w)
            if 2 < len(p):
                print(-1)
                return
            if len(p) == 1:
                s.append(v)

    if len(s) == 0:
        ans = [1] + [v for v in range(3, n)] + [2]
        if 2 < n:
            ans += [n]
        print(' '.join(list(map(str, ans))))
        return

    visited = [False] * n
    v, w = s
    while v != w and d[v] == d[w]:
        visited[v] = True
        visited[w] = True
        f = False
        for nv in path_adj_list[v]:
            if not visited[nv]:
                f = True
                v = nv
                break
        if not f:
            break
        f = False
        for nw in path_adj_list[w]:
            if not visited[nw]:
                f = True
                w = nw
                break
        if not f:
            break

    if d[v] > d[w]:
        v = s[1]
    else:
        v = s[0]

    visited = [False] * n
    visited[v] = True
    ans = [1] + [w for w in range(3, d[v] + 1)] + [2]
    c = d[v]
    v = path_adj_list[v][0]
    while True:
        visited[v] = True
        ans += [w for w in range(c + 2, c + d[v])] + [c + 1]
        c += d[v] - 1
        f = False
        for nv in path_adj_list[v]:
            if not visited[nv]:
                f = True
                v = nv
                break
        if not f:
            break

    ans += [n]

    print(' '.join(list(map(str, ans))))
    return


def main():
    n = input()
    n = int(n)
    adj_list = [[] for _ in range(n)]
    d = [0] * n
    for _ in range(n - 1):
        v, w = input().split()
        v = int(v) - 1
        w = int(w) - 1
        adj_list[v].append(w)
        adj_list[w].append(v)
        d[v] += 1
        d[w] += 1

    solve(n, adj_list, d)


if __name__ == '__main__':
    main()