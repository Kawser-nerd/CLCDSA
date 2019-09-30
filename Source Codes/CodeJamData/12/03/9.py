import sys
#RUN with PyPy for best performance!
shift=lambda l,n:l[n:]+l[:n]
def transform(x):
    smallest = x
    s = str(x)
    for i in range(len(s)):
        sh = shift(s, i)
        if sh[0]=='0': continue
        newx = int(sh)
        if newx < smallest: smallest = newx
    return smallest

transforms = [transform(x) for x in range(0, 2000001)]

#########
# Above is precomputation.
#########
T = int(sys.stdin.readline()[:-1])
for c in range(T):
    a, b = [int(x) for x in sys.stdin.readline()[:-1].split()]
    freqs = [0]*2000001
    for i in range(a, b+1):
        freqs[transforms[i]] += 1
    has = [False]*2000001
    total = 0
    for i in range(a, b+1):
        t = transforms[i]
        if has[t]: continue
        total += freqs[t] * (freqs[t]-1)/2
        has[t] = True
    print "Case #%d: %d" % (c+1, total)
