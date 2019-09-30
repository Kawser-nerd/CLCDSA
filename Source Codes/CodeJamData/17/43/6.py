import sys
import collections

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        R, C = map(int, f.readline().split())

        turrets = []
        soldiers = []

        themap = []
        for i in xrange(R):
            themap.append(f.readline().strip())
            assert len(themap[-1]) == C

        def shoot(r, c, dr, dc):
            r += dr
            c += dc

            l = []
            while r >= 0 and c >= 0 and r < R and c < C:
                if themap[r][c] == '#':
                    return l
                if themap[r][c] in '-|':
                    return None

                if themap[r][c] == '.':
                    l.append((r, c))
                    r += dr
                    c += dc
                    continue

                assert 0, themap[r][c]
            return l

        possible = True
        fixed = {}
        options = {}
        beams = []
        for r in xrange(R):
            for c in xrange(C):
                if themap[r][c] in "-|":
                    beams.append((r, c))
                    v1 = shoot(r, c, 1, 0)
                    v2 = shoot(r, c, -1, 0)
                    h1 = shoot(r, c, 0, 1)
                    h2 = shoot(r, c, 0, -1)

                    h_works = not (h1 is None or h2 is None)
                    v_works = not (v1 is None or v2 is None)

                    # print r, c, h1, h2, v1, v2
                    if h_works:
                        for p in h1 + h2:
                            options.setdefault(p, []).append(((r, c), 'h'))
                    if v_works:
                        for p in v1 + v2:
                            options.setdefault(p, []).append(((r, c), 'v'))

                    if not (h_works or v_works):
                        possible = False
                    if not h_works:
                        fixed[(r, c)] = 'v'
                    if not v_works:
                        fixed[(r, c)] = 'h'
                    # if not h_works:
                        # fixed.append((r, c), 'v')
                        # fixed_hits.update(v1)
                        # fixed_hits.update(v2)
                    # if not v_works:
                        # fixed.append((r, c), 'h')
                        # fixed_hits.update(h1)
                        # fixed_hits.update(h2)
        # print options

        ifnot = {}
        for r in xrange(R):
            for c in xrange(C):
                if themap[r][c] == '.':
                    o = options.get((r, c), [])
                    if not o:
                        possible = False
                        break
                    if len(o) == 1:
                        p, d = o[0]
                        if p not in fixed:
                            fixed[p] = d
                        elif fixed[p] != d:
                            possible = False
                    else:
                        assert len(o) == 2
                        x1, x2 = o
                        ifnot.setdefault(x1, set()).add(x2)
                        ifnot.setdefault(x2, set()).add(x1)

        # print fixed, ifnot
        q = list(fixed)

        def traverse(q):
            while q:
                p = q.pop()
                d = fixed[p]

                od = {'h': 'v', 'v': 'h'}[d]
                for then in ifnot.get((p, od), []):
                    if then[0] not in fixed:
                        fixed[then[0]] = then[1]
                        q.append(then[0])
                    elif fixed[then[0]] != then[1]:
                        return False
            return True

        possible = possible and traverse(list(fixed))

        for p in beams:
            if p in fixed:
                continue

            orig_fixed = dict(fixed)
            fixed[p] = 'h'
            q = [p]

            this_possible = traverse(q)
            if not this_possible:
                fixed = orig_fixed
                fixed[p] = 'v'
                q = [p]
                possible = possible and traverse(q)

        assert len(fixed) == len(beams)

        if not possible:
            print "Case #%d: IMPOSSIBLE" % (_T + 1,)
        else:
            print "Case #%d: POSSIBLE" % (_T + 1,)

            for r in xrange(R):
                l = []
                for c in xrange(C):
                    if themap[r][c] in "-|":
                        l.append({'h': '-', 'v': '|'}[fixed[(r, c)]])
                    else:
                        l.append(themap[r][c])
                print ''.join(l)
