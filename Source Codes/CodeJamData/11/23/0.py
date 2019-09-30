import sys
import math


def do_split(nV, vert, walls):
    if len(walls)==0:
        return [vert]
    a, b = walls[0]
    v1 = []
    v2 = []
    w1 = []
    w2 = []
    for v in vert:
        if v>=a and v<=b:
            v1.append(v)
        if not (v>a and v<b):
            v2.append(v)
    for w in walls[1:]:
        x, y = w
        if x>=a and y<=b:
            w1.append(w)
        else:
            w2.append(w) 
    return [do_split(nV, v1, w1), do_split(nV, v2, w2), a, b]

def max_vert(spl):
    if len(spl)==1:
        return len(spl[0])
    return min(max_vert(spl[0]), max_vert(spl[1]))

def colouring(nCol, spl):
    if len(spl)==1:
        vert = spl[0]
        res = {}
        c0 = 0
        for v in vert:
            res[v] = c0
            c0 = (c0 + 1) % nCol
        if res[vert[0]] == res[vert[-1]]:
            res[vert[-1]] = c0
        return res
    res = colouring(nCol, spl[0])
    r2 = colouring(nCol, spl[1])
    a = spl[2]
    b = spl[3]
    c1 = r2[a]
    c2 = r2[b]
    d1 = res[a]
    d2 = res[b]
    if c2==d1:
        (c1, c2) = (c2, c1)
        (d1, d2) = (d2, d1)
    if c1==d2 and c2!=d1:
        for v, c in r2.items():
            if c==c1:
                res[v] = d1
            elif c==c2:
                res[v] = d2
            elif c==d1:
                res[v] = c2
            else:
                res[v] = c
    else:
        for v, c in r2.items():
            if c==c1:
                res[v] = d1
            elif c==c2:
                res[v] = d2
            elif c==d1:
                res[v] = c1
            elif c==d2:
                res[v] = c2
            else:
                res[v] = c
    return res    

def solve(nV, walls):
    vert = [i for i in range(nV)]
    spl = do_split(nV, vert, walls)
    nC = max_vert(spl)
    col = colouring(nC, spl)
    return nC, [col[i] for i in range(nV)]

def readline():
    return input.readline().strip(' \r\n\t')

def do_test(input):
    line = readline().split()
    nV = int(line[0])
    nW = int(line[1])
    line1 = readline().split()
    line2 = readline().split()
    walls = [(int(s1)-1, int(s2)-1) for s1, s2 in zip(line1, line2)]
    res, col = solve(nV, walls)
    return str(res), col

input = sys.stdin

N = int(readline())

for test in range(N):
    answer, col = do_test(input)
    print 'Case #%d: %s' % (test+1, answer)
    print ' '.join(str(x+1) for x in col)
    sys.stdout.flush()
    
