import sys


def calc1(a, n):
    res = 0
    for x in a:
        if n % 2 == 1:
            res += x
        n //= 2
    return res

def calc2(a, n):
    res = []
    for x in a:
        if n % 2 == 1:
            res.append(x)
        n //= 2
    return ' '.join([str(x) for x in res])


def foo(ifile):
    a = [int(x) for x in ifile.readline().split()[1:]]
    n = len(a)
    res = {}
    for i in range(2**n):
        s = calc1(a, i)
        if s in res:
            return calc2(a, res[s]) + '\n' + calc2(a, i)
        res[s] = i
    return 'Impossible'


def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d:\n%s' % (i+1, foo(ifile))

main()

