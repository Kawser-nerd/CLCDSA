import sys

inp=sys.argv[1]
outp="%s.out" % inp.split(".")[0]

from itertools import product, combinations

def unhappiness(tenants):
    res = 0
    for c in combinations(tenants, 2):
        t1 = c[0]
        t2 = c[1]
        dx = abs(t1[0]-t2[0])
        dy = abs(t1[1]-t2[1])
        if dx == 0 and dy == 1: res += 1
        if dx == 1 and dy == 0: res += 1
    return res

def solve(r, c, n):
    return min([unhappiness(t) for t in combinations(product(range(r), range(c)), n)])

with open(inp, 'r') as f, open(outp, 'w') as out:
    cases = int(f.readline())
    for c in range(cases):
        r, cc, n = tuple([int(x) for x in f.readline()[:-1].split(" ")])
        out.write("Case #%s: %s\n" % (c+1,solve(r, cc, n)))
