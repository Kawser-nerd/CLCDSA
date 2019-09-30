import sys


cache = {}
n = None

def run2(a, idx, count, level):
    if level == n:
        if a[idx] >= count:
            return 0
        return None

    a1 = run(a, idx*2+1, count, level+1)
    a2 = run(a, idx*2+2, count, level+1)
    if a1 is None or a2 is None:
        a3 = None
    else:
        a3 = a1 + a2 + a[idx]

    a1 = run(a, idx*2+1, count+1, level+1)
    a2 = run(a, idx*2+2, count+1, level+1)
    if a1 is None or a2 is None:
        a4 = None
    else:
        a4 = a1 + a2

    if a3 is None:
        return a4
    if a4 is None:
        return a3
    return min(a3, a4)

def run(a, idx, count, level):
    if (idx, count) not in cache:
        cache[(idx, count)] = run2(a, idx, count, level)
        #print idx, count, cache[(idx, count)]
    return cache[(idx, count)]

def foo(ifile):
    global n
    n = int(ifile.readline())
    a = []
    cache.clear()
    for i in range(n+1):
        a.extend([int(x) for x in ifile.readline().split()])
    a = a[::-1]

    return run(a, 0, 0, 0)

def main(ifile):
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%s: %s' % (i+1, foo(ifile))
        #print cache
    


if __name__ == '__main__':
    main(sys.stdin)
