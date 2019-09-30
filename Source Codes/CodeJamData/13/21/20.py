def readint():
    return int(raw_input())
def readfloat():
    return float(raw_input())
def readarray(N, foo=raw_input):
    return [foo() for i in xrange(N)]
def readlinearray(foo=int):
    return map(foo, raw_input().split())

def answer(A, sizes):
    res = 0
    for size in sizes:
        #print A, size
        while A <= size:
            if A < 2:
                return 1e99
            A += A - 1
            res += 1
        A += size
    return res

case_number = readint()
for case in xrange(case_number):
    A, N = readlinearray()
    sizes = readlinearray()
    sizes.sort()
    #print([answer(A, sizes[:i]) for i in range(N + 1)])
    r = N + min([answer(A, sizes[:i]) - i for i in range(N + 1)])
    print "Case #%s: %d" % (case + 1, r)
