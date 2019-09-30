def solve(n, x, y):
    x = abs(x) # same probability on both sides
    layer = (x + y) / 2
    if layer == 0:
        below = 0
    else:
        below = tri(layer*2 - 1)
#    print below, layer, n
    if below >= n:
#        print "hasn't reached layer"
        return 0
    elif x == 0: # special case the center
#        print "center"
        return int(n >= tri(layer*2+1))
    elif layer*2 + y + 1 <= n - below:
        # can get to height using all of other side
        return 1
    else:
        n -= below

#    print n, y
    # y is height
    return chance(y+1, n)

def chance(needed, n):
    # returns chance we get to needed height with n blocks
    prob = [1.0] + [0.0 for i in xrange(n)]
    for i in xrange(n):
        for j in xrange(n-1, -1, -1):
            prob[j+1] += prob[j] / 2
            prob[j] = prob[j] / 2
#        print prob, needed, n
    return sum(prob[needed:])

def tri(n):
    return n * (n + 1) / 2

f = open('large.in', 'rU').readlines()[1:]
if not f[-1]:
    f = f[:-1]

for i in xrange(len(f)):
    n, x, y = map(int, f[i].split(' '))
    print "Case #%d: %f" % (i+1, solve(n, x, y))
