import sys
import sets

t = 'oieastbg'
d2 = dict([(t[i], str(i)) for i in range(len(t))])


def concat(a):
    r = {}
    for i in range(10):
        r[str(i)] = [0,0]
    for i in range(26):
        r[chr(ord('a')+i)] = [0,0]
    for x in a:
        r[x[0]][0]+=1
        r[x[1]][1]+=1
    res = len(a)*2
    for v in r.values():
        res -= min(v)
    if res == len(a):
        return res+1
    return res

def expand(a):
    t0 = [a[0]]
    if a[0] in d2:
        t0 = [a[0], d2[a[0]]]
    t1 = [a[1]]
    if a[1] in d2:
        t1 = [a[1], d2[a[1]]]
    for x1 in t0:
        for x2 in t1:
            yield x1+x2



def foo(ifile):
    k = int(ifile.readline())
    s = ifile.readline().strip()
    a = set([s[i:i+2] for i in range(len(s)-1)])
    b = set(sum([list(expand(x)) for x in a], []))
    return concat(b)

def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main()

