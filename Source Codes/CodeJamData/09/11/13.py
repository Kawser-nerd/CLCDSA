import sys

T = int(sys.stdin.readline())

def sumsq(n, b):
    if n == 0:
        return 0
    m = n%b
    return m**2 + sumsq(n/b, b)

def isHappy(n, b, happy, not_happy):
    if n in happy:
        return True
    if n in not_happy:
        return False

    chain = set([])

    while n != 1 and not n in chain:
        chain.add(n)
        n = sumsq(n, b)

    if n == 1:
        happy.update(chain)
        return True
    else:
        not_happy.update(chain)
        return False
        

for t in xrange(T):
    bases = [int(s) for s in sys.stdin.readline().split()]

    happy = dict([(b, set([])) for b in bases])
    not_happy = dict([(b, set([])) for b in bases])

    n = 2
    while True:
        for b in bases:
            if not isHappy(n, b, happy[b], not_happy[b]):
                # print "%d is not happy in %d" % (n, b)
                break
        else:
            print "Case #%d: %d" % (t+1, n)
            break
        n += 1
