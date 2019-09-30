import logging, re, sys
from heapq import heappush as hpush, heappop as hpop
#logging.basicConfig(level=logging.DEBUG)
logging.basicConfig(level=logging.ERROR)

AIR = True
ROCK = False

def push_fringe(fringe, pos):
    hpush(fringe, (pos.num_digs, pos))

def pop_fringe(fringe):
    return hpop(fringe)[1]

def fall_dist(map, R, pos):
    """how far will I fall from pos"""
    r_orig,c_orig = pos
    r = r_orig + 1
    while r<R and map[(r,c_orig)] == AIR:
        r = r + 1
    return r - r_orig - 1

def get_pos_after_fall(map, R, pos):
    d = fall_dist(map, R, pos)
    return (pos[0]+d, pos[1])

NEXT_MAP_ID = 1
def map_copy(map,R,C):
    global NEXT_MAP_ID
    # could try to memoize maps to prevent unneeded copies ...
    m = {}
    for k,v in map.items():
        m[k]=v
    m['id'] = NEXT_MAP_ID
    NEXT_MAP_ID += 1
    return m

def str_col(map, r, C):
    return ''.join(['.' if map[(r,c)]==AIR else '#' for c in range(C)])

def str_map(map, R, C):
    prefix ='Map %d:\n' % map['id']
    return prefix + '\n'.join([str_col(map, r, C) for r in range(R)])

class Pos():
    def __init__(self, map, r, c, num_digs):
        self.r=r
        self.c=c
        self.pos=(r,c)
        self.num_digs=num_digs
        self.map = map

    def __gen(self, R, C, F, new_pos, ret):
        map = self.map
        if map[new_pos] == AIR:
            if fall_dist(map, R, new_pos) <= F:
                # can move one to the left/right
                actual_new_pos = get_pos_after_fall(map, R, new_pos)
                ret.append(Pos(map, actual_new_pos[0], actual_new_pos[1], self.num_digs))

                # dig one to the left/right and down?
                new_dig_pos = (self.r+1, new_pos[1])
                if map[new_dig_pos] == ROCK:
                    nm = map_copy(map, R, C)
                    nm[new_dig_pos] = AIR
                    logging.debug('new map: ' + str_map(nm, R, C))
                    ret.append(Pos(nm, self.r, self.c, self.num_digs+1))

    def generate(self, R, C, F):
        ret = []
        if self.r == R - 1:
            return ret # at the bottom!

        if self.c > 0:
            self.__gen(R, C, F, (self.r, self.c-1), ret)

        if self.c < C - 1:
            self.__gen(R, C, F, (self.r, self.c+1), ret)

        return ret

    def __str__(self):
        return '(%d,%d) digs=%d map=%d' % (self.r, self.c, self.num_digs, self.map['id'])

def done_key(p):
    return (p.r, p.c, p.map['id'])

def solve(R, C, F, fringe, done):
    while fringe:
        p = pop_fringe(fringe)
        logging.debug('popped from fringe: %s' % p)
        done[done_key(p)] = True  # fastest path to a given position AND map config
        if p.r == R - 1: # goal?
            return p.num_digs # solution!

        # where to go from here?
        kids = p.generate(R, C, F)
        for kid in kids:
            if not done.has_key(done_key(kid)): # nothing better already done?
                logging.debug('new kid on fringe: %s' % kid)
                push_fringe(fringe, kid)
            else:
                logging.debug('SKIP adding kid to fringe: %s' % kid)

    return None # no solution

def readcell(s):
    assert(s=='.' or s=='#')
    if s=='.':
        return AIR
    else:
        return ROCK

def main():
    lines = sys.stdin.readlines()
    N = int(lines[0])

    L = 1
    for case in range(N):
        params = [int(x) for x in re.findall(r'\d+', lines[L])]
        L += 1
        assert(len(params) == 3)
        R, C, F = params
        logging.debug('reading in R=%d,C=%d,F=%d' % (R,C,F))

        map = {}
        for r in range(R):
            sc = lines[L][:-1] # all but \n
            cols = [readcell(x) for x in sc]
            L += 1
            assert(len(cols) == C)
            for c in range(C):
                map[(r,c)] = cols[c]

        map['id'] = 0
        logging.debug(str_map(map, R, C))
        fringe = []
        done = {}
        push_fringe(fringe, Pos(map,0,0,0)) # start at top-left with no digging done
        n = solve(R, C, F, fringe, done)
        ans = 'No' if n is None else 'Yes %d' % n
        print 'Case #%u: %s' % (case+1, ans)

main()
