import sys, collections


infile = sys.stdin

def find_square(S):
    qpos = [i for i,ch in enumerate(S) if ch=='?']
    ns = len(S)
    nq = len(qpos)
    baseval = int(S.replace('?','0'), 2)
    # all combinations of 0s and 1s for ? chars
    for i in xrange(1<<len(qpos)):
        val = baseval
        for j in xrange(nq):
            # check for qpos[j] being a 1, qpos goes left to right so index 0 is 1<<(ns-1)
            if (i & (1<<j)):
                p = 1<<(ns - qpos[j] - 1)
                val += p
        r = int(val**0.5)
        if (r*r==val):
            return bin(val)[2:]
    

T = int(infile.readline())
for i in xrange(T):
    #print i
    S = infile.readline().strip()
    result = find_square(S)

    print("Case #%d: %s" % (i+1, result))
