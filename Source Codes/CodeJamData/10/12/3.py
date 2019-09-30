import sys


def merge(g2, k, v):
    if k not in g2:
        g2[k] = v
        return
    if v < g2[k]:
        g2[k] = v
        

def foo(ifile):
    D, I, M, N = [int(x) for x in ifile.readline().split()]
    a = [int(x) for x in ifile.readline().split()]

    g = {}
    g2 = {}
    g[None] = 0
    
    for x0 in a:
        for k, v0 in g.items():
            merge(g2, k, v0+D)
            for i in range(256):
                x = i
                v = v0 + abs(x-x0)
                if k is None:
                    merge(g2, x, v)
                elif abs(k-x) <= M:
                    merge(g2, x, v)
                elif M != 0:
                    t = abs(k-x)
                    merge(g2, x, v+(t-1)//M*I)
        g = g2
        g2 = {}
    #print g
    return min(g.values())
    

def main(ifile):
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%s: %s' % (i+1, foo(ifile))

main(sys.stdin)
