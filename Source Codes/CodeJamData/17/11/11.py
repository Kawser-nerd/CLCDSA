# given assignment of cells to children, find a way to cut the cake up into
# rectangles so that (1) rectangles cover cake and (2) each initial cell ends
# up in exactly one such rectangle

# is there any harm to being greedy? problem is that there might be multiple "best" rectangles for a given cell

# G.J
# .C.
# ...

# A....
# C..B.
# .....
# .D...
# E....

# could view it as ordering problem; given first open corner, pick letter to
# engulf??

# recursively: if cake contains two letters, divide cake in two such that
# there's at least one letter on either side of the divide; otherwise, fill
# cake with that letter

def points(rlo, rhi, clo, chi):
    for r in xrange(rlo, rhi):
        for c in xrange(clo, chi):
            yield (r, c)

def recfill(cake, rlo, rhi, clo, chi):
    p1 = None
    kid = None
    p2 = None
    for r, c in points(rlo, rhi, clo, chi):
        if cake[r][c] != '?':
            if p1 is None:
                p1 = (r, c)
                kid = cake[r][c]
            else:
                p2 = (r, c)
                break
    assert p1 is not None
    if p2 is None:
        for r, c in points(rlo, rhi, clo, chi):
            cake[r][c] = kid
        return
    if p1[0] != p2[0]:
        rmid = max(p1[0], p2[0])
        recfill(cake, rlo, rmid, clo, chi)
        recfill(cake, rmid, rhi, clo, chi)
    else:
        cmid = max(p1[1], p2[1])
        recfill(cake, rlo, rhi, clo, cmid)
        recfill(cake, rlo, rhi, cmid, chi)

def solve(cake):
    recfill(cake, 0, len(cake), 0, len(cake[0]))

if __name__ == '__main__':
    import sys
    fp = open(sys.argv[1])
    def readline():
        return fp.readline().strip()
    num_cases = int(readline())
    for i in xrange(num_cases):
        nr, nc = [int(x) for x in readline().split()]
        rows = []
        for r in xrange(nr):
            rows.append(list(readline()))
        solve(rows)
        print "Case #%d:" % (i + 1)
        for row in rows:
            print ''.join(row)
