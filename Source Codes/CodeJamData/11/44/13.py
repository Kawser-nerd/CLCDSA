from collections import defaultdict

def solve(u, cnt, c, t):
    global best, bestt, vis

    if best and cnt > best:
        return

    if u in DEST:
        tt = t.difference(c)
        if best is None or cnt < best or (best == cnt and len(tt) > len(bestt)):
            best = cnt
            bestt = tt
        return
    for x in al[u]:
        if not vis.get(x):
            vis[x] = True
            nc = c.union(set([x]))
            nt = t.union(set(al[x]))
            solve(x, cnt + 1, nc, nt)
            vis[x] = False

if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        P, W = [int(s) for s in raw_input().split()]
        al = defaultdict(list)
        for s in raw_input().split():
            a, b = [int(x) for x in s.split(',')]
            al[a] += [b]
            al[b] += [a]

        DEST = dict((x, 1) for x in al[1])
        vis = {0: True}
        best = None
        bestt = None
        solve(0, 0, set([0]), set(al[0]))

        print 'Case #%d: %d %d' % (caseno + 1, best, len(bestt))
