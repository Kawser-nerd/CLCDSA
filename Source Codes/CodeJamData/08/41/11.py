import sys

def calc(a, b):
    n = len(a)
    c = [0] * n + b
    for i in range(n-1, -1, -1):
        if a[i]:
            c[i] = c[i*2+1] & c[i*2+2]
        else:
            c[i] = c[i*2+1] | c[i*2+2]
    return c[0]

def alter(a, i):
    idx = 0
    b = [x[0] for x in a]
    b2 = 0
    while i:
        if i % 2:
            if not a[idx][1]:
                return None, None
            b[idx] = 1 - b[idx]
            b2 += 1
        i //= 2
        idx += 1
    return b, b2

def foo(idx, ifile):
    M, V = tuple([int(x) for x in ifile.readline().split()])
    a = []
    for i in range((M-1)/2):
        a.append([int(x) for x in ifile.readline().split()])
    b = []
    for i in range((M+1)/2):
        b.append(int(ifile.readline().strip()))

    res = None
    for i in range(2**len(a)):
        c, c2 = alter(a, i)
        if c is None:
            continue
        if calc(c, b) != V:
            continue
        if res is None or c2 < res:
            res = c2

    if res is not None:
        print 'Case #%s: %s' % (idx, res)
    else:
        print 'Case #%s: %s' % (idx, 'IMPOSSIBLE')

def main():
    ifile = file(sys.argv[1])
    n = int(ifile.readline().strip())
    for i in range(n):
        foo(i+1, ifile)

if __name__ == '__main__':
    main()
