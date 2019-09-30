import sys


def count_require(b):
    return sum([b[-1]-x for x in b])

def calc_res(b, r, t):
    res = {}
    for x in b:
        res[x] = ((t-r+0.0)/len(b)+(b[-1]-x))/t
    return res


def foo(ifile):
    a = [int(x) for x in ifile.readline().split()[1:]]
    x = sum(a)
    b = a[:]
    b.sort()
    while count_require(b) > x:
        b = b[:-1]
    res = calc_res(b, count_require(b), x)
    return ' '.join([str(res.get(x, 0.0)*100) for x in a])




def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main()

