import sys

def foo(idx2, ifile):
    K =  int(ifile.readline().strip())
    t = [int(x) for x in ifile.readline().split()]
    n = t[0]
    d = t[1:]

    res = [i for i in range(1, K+1)]
    res2 = {}

    idx = K-1
    for i in range(1, K+1):
        ni = (idx + i) % len(res)
        res2[res[ni]] = i
        del res[ni]
        idx = ni - 1

    print 'Case #%i: %s' % (idx2, ' '.join([str(res2[x]) for x in d]))

def main():
    ifile = file(sys.argv[1])
    n = int(ifile.readline().strip())
    for i in range(n):
        foo(i+1, ifile)

if __name__ == '__main__':
    main()
