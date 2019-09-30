import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        k = int(f.readline())
        assert k == 2
        s = f.readline().strip()

        pairs = set()
        mult = "oieastbg"
        for i in xrange(len(s)-1):
            pairs.add(s[i:i+2])

        _edges = {}
        _rev_edges = {}
        for p in pairs:
            if p[0] in mult:
                c1 = (p[0], p[0].upper())
            else:
                c1 = (p[0],)
            if p[1] in mult:
                c2 = (p[1], p[1].upper())
            else:
                c2 = (p[1],)
            for _c1 in c1:
                for _c2 in c2:
                    _edges.setdefault(_c1, []).append(_c2)
                    _rev_edges.setdefault(_c2, []).append(_c1)

        def find_cycle(start):
            paths = {start:start}
            queue = [start]
            while queue:
                c = queue.pop()
                if c not in edges:
                    continue
                for next in edges[c]:
                    if next == start:
                        return paths[c]
                    if next in queue or next in paths:
                        continue
                    paths[next] = paths[c] + next
                    queue.append(next)
            return None

        best = 1e9
        for i in xrange(100):
            edges = dict((k, list(l)) for k,l in _edges.iteritems())
            rev_edges = dict((k, list(l)) for k,l in _rev_edges.iteritems())

            need = 0
            while edges:
                used = set()

                need += 1
                import random
                start = c = random.choice(edges.keys())
                used.add(c)
                while c in edges:
                    cn = edges[c].pop()
                    if not edges[c]:
                        edges.pop(c)
                    rev_edges[cn].remove(c)
                    if not rev_edges[cn]:
                        rev_edges.pop(cn)
                    c = cn
                    need += 1
                    used.add(c)

                c = start
                while c in rev_edges:
                    cn = rev_edges[c].pop()
                    if not rev_edges[c]:
                        rev_edges.pop(c)
                    edges[cn].remove(c)
                    if not edges[cn]:
                        edges.pop(cn)
                    c = cn
                    need += 1
                    used.add(c)

                while True:
                    found = False
                    for c in used:
                        cycle = find_cycle(c)
                        if not cycle:
                            continue
                        found = True
                        for i in xrange(len(cycle)):
                            c1 = cycle[i]
                            c2 = cycle[i+1] if i != len(cycle) -1 else cycle[0]
                            edges[c1].remove(c2)
                            if not edges[c1]:
                                del edges[c1]
                            rev_edges[c2].remove(c1)
                            if not rev_edges[c2]:
                                del rev_edges[c2]
                            need += 1
                            used.add(c1)
                        break
                    if not found:
                        break

            best = min(best, need)

        print "Case #%d: %d" % (_t+1, best)
