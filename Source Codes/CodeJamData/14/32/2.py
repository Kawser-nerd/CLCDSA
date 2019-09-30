def reader(inFile):
    dummy = inFile.getInt()
    return inFile.getWords()

def valid(x):
    c = set([])
    p = "|"
    for k in x:
        if k in c and p != k:
            return False
        c.add(k)
        p = k
    return True

def solver(words):
    if len([z for z in words if not valid(z)]):
        return 0
    ans = 1
    for c in "abcdefghijklmnopqrstuvwxyz":
        n = len(words)
        e = [z for z in xrange(n) for w in [words[z]] if w[-1] == c and w[0] != c]
        b = [z for z in xrange(n) for w in [words[z]] if w[0] == c and w[-1] != c]
        m = [z for z in xrange(n) for w in [words[z]] if c in w and w[0] != c and w[-1] != c]
        a = [z for z in xrange(n) for w in [words[z]] if len([k for k in w if k != c]) == 0]
        if len(m) >= 1:
            if len(e) + len(b) + len(m) + len(a) >= 2:
                # print c, words, e, b, m, a
                # print "*"
                return 0
        elif len(e) + len(b) + len(a) >= 1:
            # print c, words, e, b, m, a
            woth = [words[z] for z in xrange(n) if z not in e + b + a]
            if len(e) >= 2:
                # print "."
                return 0
            if len(b) >= 2:
                # print ","
                return 0
            wrd = ""
            for x in e:
                wrd += words[x]
            for x in a:
                wrd += words[x]
            for x in b:
                wrd += words[x]
            if not valid(wrd):
                return 0
            woth += [wrd]
            for i in xrange(1,len(a)+1):
                ans *= i
            words = [z for z in woth]
            # print ans
    for i in xrange(1,len(words)+1):
        ans *= i
    # print ans
    return (ans % (10 ** 9 + 7))

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/luke/gcj/2014/1c/b/", "b").run()
