import sys

SOURCE = object()
SINK = object()

def maxflow(edges):
    r = 0
    while True:
        q = [SOURCE]
        seen = set(q)
        prev = {}

        while q and SINK not in seen:
            next = q.pop()
            d = edges.setdefault(next, {})
            for n, e in d.iteritems():
                if not e:
                    continue
                if n in seen:
                    continue
                seen.add(n)
                q.append(n)
                prev[n] = next
        if SINK not in seen:
            break

        # print "found a flow!"
        r += 1
        cur = SINK
        while cur != SOURCE:
            next = prev[cur]
            # print "%s -> %s" % (next, cur)
            edges[next][cur] -= 1
            d = edges.setdefault(cur, {})
            d[next] = d.get(next, 0) + 1
            cur = next
    return r

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N = int(f.readline())
        L = []
        for i in xrange(N):
            L.append(f.readline().split())

        c1 = {}
        c2 = {}
        for w1, w2 in L:
            c1[w1] = c1.get(w1, 0) + 1
            c2[w2] = c2.get(w2, 0) + 1

        left1 = set(c1.keys())
        left2 = set(c2.keys())

        new_l = []
        for w1, w2 in L:
            if c1[w1] == 1 or c2[w2] == 1:
                left1.discard(w1)
                left2.discard(w2)
            else:
                new_l.append((w1, w2))

        # {source -> {dest -> capacity}}
        edges = {}

        e = edges.setdefault(SOURCE, {})
        for w1 in left1:
            e[(w1, 1)] = 1
        for w2 in left2:
            edges[(w2, 2)] = {SINK: 1}
        for w1, w2 in new_l:
            edges.setdefault((w1, 1), {})[(w2, 2)] = 1

        # print edges

        doubles = maxflow(edges)
        singles = len(left1) + len(left2) - 2 * doubles
        maxfake = len(new_l) - singles - doubles

        print "Case #%d: %s" % (_T + 1, maxfake)
