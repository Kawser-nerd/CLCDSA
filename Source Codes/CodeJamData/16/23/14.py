#!/usr/bin/env python3

from collections import deque

TEST = 'large'
IN = 'C-{}.in'.format(TEST)
OUT = 'C-{}.out'.format(TEST)


def find_path(src, dst, adj):
    n = len(adj)
    par = [None] * n
    par[src] = src
    q = deque()
    q.append(src)
    while q and par[dst] is None:
        x = q.popleft()
        for y in adj[x]:
            if par[y] is None:
                par[y] = x
                q.append(y)
    if par[dst] is None:
        return
    path = [dst]
    x = dst
    while x != src:
        x = par[x]
        path.append(x)
    return list(reversed(path))


def run(topics):
    first = list({t[0] for t in topics})
    second = list({t[1] for t in topics})

    nf, ns = len(first), len(second)
    src = 0
    first_id = {w: i for i, w in enumerate(first, 1)}
    second_id = {w: i for i, w in enumerate(second, 1 + nf)}
    dst = 1 + nf + ns
    
    adj = [set() for i in range(nf + ns + 2)]
    for i in first_id.values():
        adj[src].add(i)
    for i in second_id.values():
        adj[i].add(dst)
    for a, b in topics:
        adj[first_id[a]].add(second_id[b])

    while True:
        path = find_path(src, dst, adj)
        if path is None:
            break
        for i in range(1, len(path)):
            a, b = path[i-1:i+1]
            adj[a].remove(b)
            adj[b].add(a)
    
    cnt = 0
    for a, b in topics:
        ai = first_id[a]
        bi = second_id[b]
        if ai in adj[src] or dst in adj[bi]:
            if ai in adj[src]:
                adj[src].remove(ai)
            if dst in adj[bi]:
                adj[bi].remove(dst)
            adj[ai].remove(bi)
        elif bi in adj[ai]:
            cnt += 1
    return cnt


def main():
    with open(IN) as fin, open(OUT, 'w') as fout:
        t = int(fin.readline().strip())
        for i in range(t):
            n = int(fin.readline().strip())
            topics = [fin.readline().split() for i in range(n)]
            res = run(topics)
            print('Case #{}: {}'.format(i + 1, res), file=fout)
            print('Case #{}: {}'.format(i + 1, res))


if __name__ == '__main__':
    main()
