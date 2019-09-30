import sys

def perm(a):
    if len(a) == 1:
        yield a
        return
    for i in range(len(a)):
        for x in perm(a[:i] + a[i+1:]):
            yield [a[i]] + x

def calc(x, y):
    return ''.join([y[z] for z in x])

def calc2(x):
    x = ''.join(x)
    res = 0
    last = None

    for y in x:
        if y != last:
            res += 1
        last = y
    return res

def foo(idx, ifile):
    k =  int(ifile.readline().strip())
    S = ifile.readline().strip()
    ss = [S[x:x+k] for x in range(0, len(S), k)]

    res = len(S)
    for x in perm(range(k)):
        ss2 = [calc(x, y) for y in ss]
        res = min(res, calc2(ss2))
    print 'Case #%s: %s' % (idx, res)


def main():
    ifile = file(sys.argv[1])
    n = int(ifile.readline().strip())
    for i in range(n):
        foo(i+1, ifile)

if __name__ == '__main__':
    main()
