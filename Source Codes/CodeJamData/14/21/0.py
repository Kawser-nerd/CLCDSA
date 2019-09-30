import sys
import itertools

inp = sys.stdin
outp = sys.stdout

def norm(s):
    return ''.join([c for (c,x) in itertools.groupby(s)])

def mul(s):
    res = []
    for (c,it) in itertools.groupby(s):
        r = 0
        for a in it:
            r +=1
        res.append(r)
    return res
    
def solve():
    n = int(inp.readline())
    strs = [inp.readline()[:-1] for i in range(n)]
    for i in range(1, n):
        if norm(strs[i]) != norm(strs[0]):
            print 'Fegla Won'
            return
    vals = [mul(strs[i]) for i in range(n)]
    tot = 0
    for j in range(len(vals[0])):
        x = sorted([vals[i][j] for i in range(n)])
        med = x[n/2]
        for i in range(n):
            tot += abs(med-x[i])
    print tot









T = int(inp.readline())
for i in range(T):
    outp.write('Case #%d: ' % (i+1))
    solve()
