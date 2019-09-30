# Linguo entry for Problem E in 2015 Google Code Jam Round 3 'The Battle for Seattle'

# D = 1: [a,b,a,b] -> a+b
# D = 2: [a,b,c,d,a,b,c,d] -> (a+b+c+d)/2 if it is possible

# 1/(1-x^2), x/(1-x^2) 

# [a, 0, a, 0]
# [0, b, 0, b]
# [c, c, 0, 0]
# [0, d, d, 0]
# [0, 0, e, e]
# [f, 0, 0, f]


def reader(inFile):
    (n, d) = inFile.getInts()
    seq = inFile.getInts()
    return (n, d, seq)

def possible(seq,D):
    myseq = [z for z in seq]
    w = [seq[i]-seq[i-1] for i in xrange(len(seq))]
    tot = 0
    while True:
        for j in xrange(D):
            if (w[j] + w[j + D]) % 2 == 1:
                return False, -1
            else:
                scr = (w[j] - w[j + D]) / 2
                if w[j] >= w[j + D]:
                    tot += scr
                    myseq = myseq[:j] + [z - scr for z in myseq[j:j+D]] + myseq[j+D:2*D]
                else:
                    tot -= scr
                    myseq = [z+scr for z in myseq[:j]] + myseq[j:j+D] + [z+scr for z in myseq[j+D:2*D]]
                if min(myseq) < 0:
                    return False, -1
                w[j] = (w[j] + w[j + D]) / 2
        if D == 1:
            break
        D = D >> 1
    return True, tot

def solver((n, d, seq)):
    if len([i for i in xrange(n-2*d) if seq[i] != seq[i+2*d]]):
        return "CHEATERS!"
    poss, tot = possible(seq[:2*d], d)
    if not poss:
        return "CHEATERS!"
    return tot

if True and __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/luke/gcj/2015/3/e/", "e").run()

if False:
    x = set([(0,0,0,0)])
    y = set([(1,0,1,0),(0,1,0,1),(1,1,0,0),(0,1,1,0),(0,0,1,1),(1,0,0,1)])
    
    for k in xrange(1,10):
        x = set([tuple(a[i]+b[i] for i in xrange(4)) for a in x for b in y])
        print k, max([z for w in x for z in w])
        print k, [(p,q,r,s) for p in xrange(2 * k + 1) for q in xrange(2 * k + 1 - p) for r in xrange(2 * k + 1 - p - q) for s in [2 * k - p - q - r] if (p, q, r, s) not in x and max(p,q,r,s) <= k]

if False:
    x = set([(0,0,0,0,0,0,0,0)])
    x2 = set([(0,0,0,0,0,0,0,0)])
    y = set([(1,0,1,0,1,0,1,0),(0,1,0,1,0,1,0,1),(1,1,0,0,1,1,0,0),(0,1,1,0,0,1,1,0),(0,0,1,1,0,0,1,1),(1,0,0,1,1,0,0,1),(1,1,1,1,0,0,0,0),(0,1,1,1,1,0,0,0),(0,0,1,1,1,1,0,0),(0,0,0,1,1,1,1,0),(0,0,0,0,1,1,1,1),(1,0,0,0,0,1,1,1),(1,1,0,0,0,0,1,1),(1,1,1,0,0,0,0,1)])
    for k in xrange(1,6):
        x = set([tuple(a[i]+b[i] for i in xrange(8)) for a in x for b in y])
        x2 = set([tuple(a[i]+(1 if i == j else 0) for i in xrange(8)) for a in x2 for j in xrange(8)])
        x2 = set([tuple(a[i]+(1 if i == j else 0) for i in xrange(8)) for a in x2 for j in xrange(8)])
        x2 = set([tuple(a[i]+(1 if i == j else 0) for i in xrange(8)) for a in x2 for j in xrange(8)])
        x2 = set([tuple(a[i]+(1 if i == j else 0) for i in xrange(8)) for a in x2 for j in xrange(8)])
        x2 = [z for z in x2 if max(z) <= k]
        print k, [v for v in x2 if v not in x and possible(v,4)], len(x), len(x2)

# (1,2,0,0,1,2,0,2)
# (-1,1,-2,0,1,1,-2,2)
# 0,1,1,3,1,2,2,2
# 0,1,0,1,0,1,0,1
# 0,0,1,1,0,0,1,1
# 0,0,0,1,1,1,1,0

# -1, 1,-1, 1,-1, 1,-1,  1
# -1, 0, 1, 0,-1, 0, 1,  0
#  0, 0, 0, 1, 0, 0, 0, -1
