import re, sys
from heapq import heappush as hpush, heappop as hpop

NE = 0 # top right
NW = 1 # top left
SE = 2 # bottom right
SW = 3 # bottom left

def str_corner(corner):
    if corner==NE:
        return 'NE'
    elif corner == NW:
        return 'NW'
    elif corner == SE:
        return 'SE'
    elif corner == SW:
        return 'SW'
    else:
        return '??'

def is_north(corner):
    return corner <= 1

def is_east(corner):
    return corner==0 or corner==2

def flop_ns(corner):
    if is_north(corner):
        return corner + 2
    else:
        return corner - 2

def flop_ew(corner):
    if is_east(corner):
        return corner + 1
    else:
        return corner - 1

def push_fringe(fringe, pos):
    hpush(fringe, (pos.t, pos))

def pop_fringe(fringe):
    return hpop(fringe)[1]

class Intersection:
    def __init__(self, S, W, T):
        self.ns = S
        self.ew = W
        self.ct = S + W
        self.t0 = T

    def get_offset(self, t):
        return (t - self.t0) % self.ct

    def time_until_change(self, t):
        o = self.get_offset(t)
        if o < self.ns:
            return self.ns - o
        else:
            return self.ct - o

    def cross_change(self, corner, t):
        """Change in position if we cross the screet now - stay at SAME
        INTERSECTION, but new corner."""
        if self.get_offset(t) < self.ns: # green N/S
            return (0, 0, flop_ns(corner))
        else:
            return (0, 0, flop_ew(corner))

    @staticmethod
    def block_change_ns(corner):
        """Change in position if we walk n/s down the block."""
        dr = -1 if is_north(corner) else 1
        return (dr, 0, flop_ns(corner))

    @staticmethod
    def block_change_ew(corner):
        """Change in position if we walk e/w down the block."""
        dc = 1 if is_east(corner) else -1
        return (0, dc, flop_ew(corner))

class Pos:
    def __init__(self, r, c, corner, t):
        self.r = r
        self.c = c
        self.corner = corner  # relative to INTERSECTION not the block
        self.t = t

    def make_pos(self, change, dt):
        dr, dc, new_corner = change
        return Pos(self.r+dr, self.c+dc, new_corner, self.t + dt)

    def generate(self, I):
        """all possible moves from current pos"""
        i = I[(self.r,self.c)]
        t = self.t
        tc = i.time_until_change(t)
        return [
            # option 1: cross street now
            self.make_pos(i.cross_change(self.corner, t), 1),

            # option 2: wait until light changes and then cross
            self.make_pos(i.cross_change(self.corner, t+tc), tc+1),

            # option 3: switch corner (flop ns)
            self.make_pos(Intersection.block_change_ns(self.corner), 2),

            # option 4: switch corner (flop ew)
            self.make_pos(Intersection.block_change_ew(self.corner), 2)
            ]

    def is_goal(self, NC):
        return self.r==0 and self.corner==NE and self.c==NC-1

    def __str__(self):
        return '(%d,%d):%s,t=%d' % (self.r,self.c,str_corner(self.corner),self.t)

def done_key(p):
    return (p.r, p.c, p.corner)

def solve(I, NR, NC, fringe, done):
    # intersections info dictionary, #rows, #cols, fringe
    while fringe:
        # greedily choose the earliest node on the fringe
        p = pop_fringe(fringe)
        print 'expanding %s' % p
        done[done_key(p)] = True  # found fastest path to r, c
        if p.is_goal(NC):
            return p.t # got to goal in this amount of time

        # figure out where we can go from here
        kids = p.generate(I)
        for kid in kids:
            if kid.r>=0 and kid.r<NR and kid.c>=0 and kid.c<NC: # in bounds?
                if not done.has_key(done_key(kid)): # nothing better finalized?
                    push_fringe(fringe, kid)
                    print '  generated %s' % kid
                else:
                    print '  discarded %s (have something better)' % kid
            else:
                print '  ignoring %s (out of bounds)' % kid


    assert(False) # no solution found

def main():
    lines = sys.stdin.readlines()
    C = int(lines[0])

    l = 1
    for c in range(C):
        params = [int(x) for x in re.findall(r'\d+', lines[l])]
        l += 1
        assert(len(params) == 2)
        N, M = params

        intersections = {}
        for n in range(N):
            params = [int(x) for x in re.findall(r'\d+', lines[l])]
            l += 1
            assert(len(params) == 3 * M)

            for m in range(M):
                o = m * 3
                S, W, T = params[o+0], params[o+1], params[o+2]
                intersections[(n, m)] = Intersection(S, W, T)
                #print '%u,%u = ns=%u ew=%u t0=%u' % (n,m,S,W,T)

        fringe = []
        done = {}
        start = Pos(N-1, 0, SW, 0)
        push_fringe(fringe, start)
        min_time = solve(intersections, N, M, fringe, done)

        print 'Case #%u: %u' % (c+1, min_time)

main()
