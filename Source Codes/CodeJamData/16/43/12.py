"""
hedge mazes: given garden and pairs of courtiers that live around garden, construct hedge maze such that pairs of courtiers are connected exclusively

is solution necessarily unique? start with UL corner; if two corner courtiers are connected, then /, else \

not all of garden must be used; consider

    /\
    \/

in any valid layout, there must be two adjacent courtiers who are in love, correct? efficiently connect them?

ok, let's greedily connect courtiers that are adjacent; if we can do so then we have a garden

NOTE: can rotate problem 45 degrees to make it easier?
"""

def solve(nr, nc, pairs):
    # figure out pairs of adjacent points to connect
    pis = [None] * (2 * (nr + nc))
    for (pi, (i, j)) in enumerate(pairs):
        pis[i] = pi
        pis[j] = pi
    sorted_pairs = []
    while pis:
        if pis == [0, 1, 0, 1]:
            #import pdb; pdb.set_trace()
            pass
        if pis[0] == pis[-1]:
            sorted_pairs.append(pairs[pis[0]])
            del pis[0]
            del pis[-1]
            continue
        for k in xrange(len(pis) - 1):
            if pis[k] == pis[k + 1]:
                sorted_pairs.append(pairs[pis[k]])
                del pis[k:k + 2]
                break
        else:
            print "IMPOSSIBLE" # nested lover pair
            return

    # connect pairs in garden
    grid = [[None] * nc for r in xrange(nr)]
    def courtier_coords(i):
        if i < nc: # north
            return (-1, i, 1, 0)
        i -= nc
        if i < nr: # east
            return (i, nc, 0, -1)
        i -= nr
        if i < nc: # south
            return (nr, nc - i - 1, -1, 0)
        i -= nc # west
        return (nr - i - 1, -1, 0, 1)

    def trace(i, j, commit=False):
        r, c, dr, dc = courtier_coords(i)
        rj, cj, _, _ = courtier_coords(j)
        r += dr
        c += dc
        trail = []
        while r in xrange(nr) and c in xrange(nc):
            if grid[r][c] is None or (grid[r][c] == '/' and dr != 0) or (grid[r][c] == '\\' and dc != 0):
                dr, dc = dc, -dr # turn right
                trail.append((r, c, '/' if dr == 0 else '\\'))
            else:
                dr, dc = -dc, dr # turn left
                trail.append((r, c, '\\' if dr == 0 else '/'))
            r += dr
            c += dc
        if (r, c) != (rj, cj):
            return None
        if commit:
            for (r, c, tile) in trail:
                grid[r][c] = tile
        return len(trail)

    for (i, j) in sorted_pairs:
        forward_len = trace(i, j)
        backward_len = trace(j, i)
        if forward_len is not None:
            if backward_len is not None and backward_len < forward_len:
                trace(j, i, commit=True)
            else:
                trace(i, j, commit=True)
        elif backward_len is not None:
            trace(j, i, commit=True)
        else:
            print 'IMPOSSIBLE'
            return
        
    for r in xrange(nr):
        for c in xrange(nc):
            if grid[r][c] is None:
                grid[r][c] = '/'
    for r in xrange(nr):
        print ''.join(grid[r])

if __name__ == '__main__':
    import sys
    fp = open(sys.argv[1])
    def readline():
        return fp.readline().strip()
    num_cases = int(readline())
    for i in xrange(num_cases):
        nr, nc = [int(x) for x in readline().split()]
        pair_tokens = [int(x) - 1 for x in readline().split()]
        pairs = [pair_tokens[j:j+2] for j in xrange(0, len(pair_tokens), 2)]
        print "Case #%d:" % (i + 1)
        solve(nr, nc, pairs)
