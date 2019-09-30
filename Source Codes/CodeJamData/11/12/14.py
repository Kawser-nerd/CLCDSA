import sys

def same(w1, w2, l):
    for i in xrange(len(w1)):
        c1 = w1[i]
        c2 = w2[i]
        if c1 == c2:
            continue
        if c1 in l or c2 in l:
            return False
    return True

def score(ans, words, l):
    candidates = [w for w in words if len(w) == len(ans)]
    sc = 0
    for i, c in enumerate(l):
        for w in candidates:
            if c in w:
                break
        else:
            continue

        candidates = [w for w in candidates if same(w, ans, l[:i+1])]

        if not c in ans:
            sc += 1
    return sc

def doit(l):
    best = -1
    bestw = None
    for w in words:
        sc = score(w, words, l)
        if sc > best:
            best = sc
            bestw = w
    return bestw

def gcd(a, b):
    if a > b:
        a, b = b, a
    if a == 0:
        return b
    return gcd(b % a, a)

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        n, m = map(int, f.readline().split())
        words = []
        lists = []
        for i in xrange(n):
            words.append(f.readline().strip())
        for j in xrange(m):
            lists.append(f.readline().strip())

        print "Case #%d: %s" % (_t + 1, " ".join(map(doit, lists)))

