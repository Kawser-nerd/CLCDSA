import io, sys
import datetime

fin = None
    
def solve():
    n, r, p, s = nums()
    f = {'R' : 'S', 'S' : 'P', 'P' : 'R'}
    def build(lev, c):
        if lev == 0:
            return c
        a = build(lev-1, c)
        b = build(lev-1, f[c])
        if a < b:
            return a + b
        return b + a
    res = 'Z'
    
    def cnt(s, x):
        res = 0
        for c in s:
            if c == x:
                res += 1
        return res
    
    for base in 'RPS':
        t = build(n, base)
        if cnt(t, 'R') != r:
            continue
        if cnt(t, 'P') != p:
            continue
        if cnt(t, 'S') != s:
            continue
        res = min(res, t)
    if res == 'Z':
        res = 'IMPOSSIBLE'
    return res
        
def main():
    fname = 'test.in'
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    global fin    
    fin = io.open(fname)
    fout = io.open(fname + '.out', 'w')
    t0 = datetime.datetime.now()    
    t = int(fin.readline())
    
    for i in range(t):
        fout.write('Case #%d: ' % (i + 1))
        fout.write('%s\n' % str(solve()))
    
    print('Time = %s' % str(datetime.datetime.now() - t0))
    fin.close()
    fout.close()

def nums():
    return [int(x) for x in fin.readline().split()]
def fnums():
    return [float(x) for x in fin.readline().split()]
def num():
    return int(fin.readline())
def sstrip():
    return fin.readline().strip()
def strs():
    return fin.readline().split()
def arrstr(a, sep = ' '):
    return sep.join([str(x) for x in a])

if __name__ == '__main__':
    main()    