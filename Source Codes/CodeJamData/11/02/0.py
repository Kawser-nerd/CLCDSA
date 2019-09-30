import sys

def doit(combines, opposed, l):
    # print combines, opposed, l
    cur = []
    for c in l:
        cur.append(c)
        while len(l) > 2 and tuple(sorted(cur[-2:])) in combines:
            new = combines[tuple(sorted(cur[-2:]))]
            cur.pop()
            cur.pop()
            cur.append(new)
        cont = set(cur)
        for o in opposed:
            if o[0] in cont and o[1] in cont:
                cur = []
    return cur

class Str(object):
    def __init__(self, s):
        self.s = s

    def __str__(self):
        return self.s

    def __repr__(self):
        return self.s


if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        s = f.readline().split()
        c = int(s[0])
        combines = []
        for i in xrange(1, c+1):
            combines.append(s[i])
        combines = dict([(tuple(sorted(cm[:2])), cm[2]) for cm in combines])
        d = int(s[c+1])
        opposed = []
        for i in xrange(2 + c, 2 + c + d):
            opposed.append(s[i])
        n = doit(combines, opposed, s[-1])
        print "Case #%d:" % (_t+1), str(map(Str, n))

