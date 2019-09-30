import psyco
psyco.full()

INF = 2**30

def gen_perm(s):
    if len(s) == 1:
        yield s
    else:
        for p in gen_perm(s[:-1]):
            for i in xrange(len(p)+1):
                yield p[0:i] + [s[-1]] + p[i:]


def permute(S, perm):
    blocks = []
    k = len(perm)
    for i in xrange(0,len(S),k):
        t = S[i:i+k]
        t = ''.join(t[j] for j in perm)
        blocks.append(t)

    return ''.join(blocks)

def count(s):
    res = 1
    for i, ch in enumerate(s[1:]):
        if ch != s[i]:
            res += 1

    return res

def solve():
    for case in xrange(input()):
        k = input()
        S = raw_input()

        p = range(0, k)
        perms = list(gen_perm(p))

        res = INF
        for p in perms:
            ns = permute(S, p)
            c = count(ns)
            res = min(res, c)

        print 'Case #%d: %d' % (case+1, res)

solve() # so that psyco can do its magic
