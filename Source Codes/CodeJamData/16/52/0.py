if 1:
    from sys import *
    from functools import *
    from collections import *
    from itertools import *
    from functools import *
    from heapq import *
    xr = xrange

    def print_args(*args, **kwargs):
        return ','.join(value for value in [','.join(map(repr, args)),','.join("%s=%s" % (k, repr(v)) for k, v in kwargs.items())] if value)

    def print_result(before=False, after=True):
        def fc(func):
            @wraps(func)
            def f(*args, **kwargs):
                if before:
                    print "%s(%s)"      % (func.__name__, print_args(*args, **kwargs))
                r = func(*args, **kwargs)
                if after:
                    print "%s(%s) = %s" % (func.__name__, print_args(*args, **kwargs), r)
                return r
            return f
        return fc

    def memoize(function):
        memo = {}
        @wraps(function)
        def f(*args):
            key = args
            if key not in memo:
                memo[key] = function(*args)
                if not (len(memo) & 32767):
                    print >>stderr, "memo", function.__name__, len(memo)
            return memo[key]
        f.memo = memo
        return f

    def line():
        return raw_input().strip()

    def parts(f=int):
        return map(f, line().split())

    def qparts(f=int):
        data = line().split()
        return data[0], map(f, data[1:])

def process(n,preq,word,m,cools):
    n += 1
    parent = [0]*n
    children = [[] for i in xrange(n)]
    word = [''] + list(word)
    for i in xrange(1,n):
        j = preq[i-1]
        parent[i] = j
        children[j].append(i)

    return n,parent,children,word,m,cools


def randcombine(words):
    indices = []
    for i in xrange(len(words)):
        indices += [i]*len(words[i])
    starts = [0]*len(words)
    shuffle(indices)
    total = []
    for i in indices:
        total.append(words[i][starts[i]])
        starts[i] += 1
    return ''.join(total)


def randword(n,parent,children,word):
    def randword(i):
        words = []
        for j in children[i]:
            words.append(randword(j))

        return word[i] + randcombine(words)
    return randword(0)


def adds((n,parent,children,word,m,cools)):
    w = randword(n,parent,children,word)
    w = ''.join(w)
    return [cool in w for cool in cools]


from random import *
seed(11)

def main():
    z = input()
    totals = [None]*z
    counts = [0]*z
    cases = [None]*z
    for cas in xrange(z):
        n = input()
        preq = parts()
        word = line()
        m = input()
        cools = parts(str)
        totals[cas] = [0]*m
        cases[cas] = process(n,preq,word,m,cools)


    from itertools import count

    # kill when you're done
    for it in count(1):
        for cas in xrange(z):
            v = adds(cases[cas])
            for i in xrange(len(v)):
                totals[cas][i] += v[i]
            counts[cas] += 1

        if it & 31: continue

        with open('b_basura_out%s.out' % it, 'w') as f:
            with open('b_basura_last.out', 'w') as g:
                for cas in xrange(z):
                    res = []
                    for i in xrange(len(totals[cas])):
                        ans = float(totals[cas][i]) / counts[cas]
                        res.append(ans)
                    #print "Case #%s:" % (cas+1)
                    ans = ' '.join("%.11f" % v for v in res)
                    x = "Case #%s: %s" % (cas+1, ans)
                    print >>f, x
                    print >>g, x
                    print x

main()
