import sys



# a0*b0*(b1-1)
# a0*(100/c0)*(100/c1-1)
# a0*100*(100-c1)
def cmp1(x0, x1):
    i0, a0, b0 = x0
    i1, a1, b1 = x1
    t1 = a0*(100-b1)
    t2 = a1*(100-b0)
    if t1 == t2:
        return i0 - i1
    if t1 < t2:
        return -1
    return 1

def foo(ifile):
    n = int(ifile.readline())
    a = [int(x) for x in ifile.readline().split()]
    b = [int(x) for x in ifile.readline().split()]
    b = [(100.0-x) for x in b]
    c = [(i, a[i], b[i]) for i in range(n)]
    c = sorted(c, cmp=cmp1)
    return ' '.join([str(x[0]) for x in c])


def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main()

