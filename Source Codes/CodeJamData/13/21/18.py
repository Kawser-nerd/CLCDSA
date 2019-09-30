def solve(a, motes):
    result = 100000000000
    for upto in xrange(len(motes)+1):
        result = min(result, len(motes) - upto + getmin(a, motes[:upto]))
#        print "%d - %d + getmin(%d, %s)" % (len(motes), upto, a,
#                motes[:upto])
    return result

def getmin(a, motes):
    upto = ops = 0
    while upto < len(motes):
        if a <= motes[upto]:
#            print motes, upto, a, ops
            if a < 2:
                ops = 10000000000
                break
            a += a-1
            ops += 1
        else:
            a += motes[upto]
            upto += 1
    return ops


f = open('large.in', 'rU').readlines()[1:]
if not f[-1]:
    f = f[:-1]

for i in xrange(0, len(f), 2):
    a, n = map(int, f[i].split(' '))
    motes = sorted(map(int, f[i+1].split(' ')))
    print "Case #%d: %d" % (i/2+1, solve(a, motes))
