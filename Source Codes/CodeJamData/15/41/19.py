import sys


class Node:
    def __init__(self, r,c,d,R,C):
        self.r = r
        self.c = c
        if d == '.':
            self.rd = 0
            self.cd = 0
            self.maxmoves = -1
        if d == '^':
            self.rd = -1
            self.cd = 0
            self.maxmoves = r
        if d == '>':
            self.rd = 0
            self.cd = 1
            self.maxmoves = C-c-1
        if d == '<':
            self.rd = 0
            self.cd = -1
            self.maxmoves = c
        if d == 'v':
            self.rd = 1
            self.cd = 0
            self.maxmoves = R-r-1

    def getmm(self):
        return self.maxmoves

    def move(self, i):
        return (self.r + i*self.rd, self.c + i*self.cd)

def run(R,C,grid):
    def checkgood(r,c,d):
        node = Node(r,c,d,R,C)
        mm = node.getmm()
        for i in xrange(1, mm+1):
            rp, cp = node.move(i)
            if grid[rp][cp] != '.':
                return True
        return False

    full = frozenset(['>','<','v','^'])
    count = 0
    for r in xrange(R):
        for c in xrange(C):
            if grid[r][c] == '.':
                continue
            if checkgood(r,c,grid[r][c]):
                continue
            count += 1
            remaining = full - set([grid[r][c]])
            alive = False
            for dd in remaining:
                if checkgood(r,c,dd):
                    alive = True
                    break
            if not alive:
                return 'IMPOSSIBLE'
    return count


fin = open(sys.argv[1])

T = int(fin.readline().strip())
for i in range(1,T+1):
    R,C = [int(x) for x in fin.readline().strip().split()]
    grid = []
    for iii in range(R):
        grid.append(fin.readline().strip())
    ans = run(R,C,grid)
    print('Case #%d: %s' % (i, ans))
