import itertools
from copy import deepcopy
input = raw_input

def is_ok(sol):
    for w in sol:
        c = 0
        for w2 in sol:
            if w != w2:
                for u, v in zip(w, w2):
                    if u == v == True:
                        return False
            else:
                c += 1
        if c != sum(w):
            return False
    return True

def solve(pos):
    positions = [(i, j) for i in range(len(pos)) for j in range(len(pos)) if pos[i][j] == False]
    for r in range(len(positions) + 1):
        for s in itertools.combinations(positions, r):
            npos = deepcopy(pos)
            for p in s:
                npos[p[0]][p[1]] = True
            if is_ok(npos):
                return r

t = int(input())
for i in range(t):
    print "Case #%d:" % (i + 1),
    n = int(input())
    l = []
    for i in range(n):
        w = [bool(int(r)) for r in input().strip()]
        l.append(w)
    print(solve(l))
    
