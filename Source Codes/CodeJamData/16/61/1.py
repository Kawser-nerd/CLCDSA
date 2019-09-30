from __future__ import division, print_function

t = int(input())

N = 0
OR = 1
STAR = 2

def parse(r, i):
    l = []
    i0 = i
    while i < len(r):
        if r[i] == "|" or r[i] == ")":
            return tuple(l), i + 1
        if r[i] == "(":
            elem, i = parse(r, i + 1)
            elems = [elem]
            while r[i - 1] == "|":
                elem, i = parse(r, i)
                elems.append(elem)
            if i < len(r) and r[i] == "*":
                l.append((STAR, elem))
                assert len(elems) == 1
                i += 1
            else:
                l.append((OR, tuple(elems)))
        elif "0" <= r[i] <= "9":
            l.append((N, int(r[i])))
            i += 1
        else:
            print(r[i])
            assert False
    return tuple(l), i

def nulle(r):
    if r[0] == N:
        return False
    elif r[0] == STAR:
        return True
    elif r[0] == OR:
        return any(null(x) for x in r[1])

def null(r):
    return all(nulle(x) for x in r)

"""
def deprefe(r, n):
    if r[0] == N:
        if r[1] == n:
            return ()
        else:
            return None
    elif r[0] == OR:
        z = [depref(u, n) for u in r[1]]
        z = [x for x in z if x != None]
        if len(z) == 0: return None
        elif len(z) == 1: return z[0]
        else: return ((OR, tuple(z)),)
    elif r[0] == STAR:
        z = depref(r[1], n)
        if z != None:
            return z + ((STAR, r[1]),)
        else:
            return None

def depref(r, n):
    if r == None:
        return None
    lll = []
    for i, x in enumerate(r):
        u = deprefe(x, n)
        if u != None:
            lll.append(tuple(deprefe(x, n) + r[i+1:]))
        if not nulle(x):
            break
    if len(lll) == 0: return None
    elif len(lll) == 1: return lll[0]
    return ((OR, lll), )

d = {}
def count(r1, r2, x):
    if r1 == None:
        return 0
    if x == 0:
        return 1
    if (r1, r2, x) in d:
        return d[(r1, r2, x)]
    s = 0
    for i in range(10):
        u = depref(r1, i)
        v = depref(r2, i)
        s += count(u, v, x - 1)
    d[(r1, r2, x)] = s
    return s

def cnt(r, a, b):
    x = 0
    s = 0
    while b >= 10 ** x:
        aa = min(10 ** (x + 1) - 1, max(10 ** x, a))
        bb = min(10 ** (x + 1) - 1, b)
        u, v = str(aa), str(bb)
        assert len(u) == len(v) == x + 1
        x += 1
        
    return s
"""

EPS = -1

def mk(r, n, sst, est):
    if len(r) == 0:
        return {sst : [(EPS, est)]}, n
    else:
        sts = [sst] + list(range(n, n + len(r) - 1)) + [est]
        n += len(r) - 1
        d = {}
        for i in range(len(r)):
            if r[i][0] == N:
                d.setdefault(sts[i], []).append((r[i][1], sts[i + 1]))
            elif r[i][0] == STAR:
                #print(n)
                u, v = n, n + 1
                n += 2
                d.setdefault(sts[i], []).append((EPS, u))
                d.setdefault(sts[i], []).append((EPS, sts[i + 1]))
                d[v] = [(EPS, sts[i + 1]), (EPS, u)]
                dd, n = mk(r[i][1], n, u, v)
                for key in dd:
                    d.setdefault(key, []).extend(dd[key])
            elif r[i][0] == OR:
                for w in r[i][1]:
                    u, v = n, n + 1
                    n += 2
                    d.setdefault(sts[i], []).append((EPS, u))
                    d[v] = [(EPS, sts[i + 1])]
                    dd, n = mk(w, n, u, v)
                    for key in dd:
                        d.setdefault(key, []).extend(dd[key])
        return d, n

def make_auto(r):
    return mk(r, 2, 0, 1)

def eps_flood(r, sts):
    pile = list(sts)
    w = set(sts)
    while len(pile) > 0:
        u = pile.pop()
        for key in r.get(u, []):
            if key[0] == EPS and key[1] not in w:
                w.add(key[1])
                pile.append(key[1])
    return frozenset(w)

def after(r, sts, n):
    w = set()
    for st in sts:
        for key in r.get(st, []):
            if key[0] == n:
                w.add(key[1])
    return eps_flood(r, w)

def match_between(stored, r, sts, a, b):
    if (sts, a, b) in stored:
        return stored[(sts, a, b)]
    z = match_between_(stored, r, sts, a, b)
    stored[(sts, a, b)] = z
    return z

def match_between_(stored, r, sts, a, b):
    if len(a) == 0:
        if 1 in sts:
            return 1
        return 0
    c = 0
    for i in range(int(a[0]), int(b[0]) + 1):
        lo = "0" * (len(a) - 1)
        if i == int(a[0]):
            lo = a[1:]
        hi = "9" * (len(a) - 1)
        if i == int(b[0]):
            hi = b[1:]
        c += match_between(stored, r, after(r, sts, i), lo, hi)
    return c

for i in range(t):
    print("Case #%d:" % (i + 1), end = " ")
    a, b = map(int, input().split())
    r = input().strip()
    r, _ = parse(r, 0)
    #print(r)
    #print(cnt(r, a, b))
    auto, n = make_auto(r)
    init = eps_flood(auto, [0])
    x = 0
    stored = {}
    c = 0
    #print(auto)
    while 10 ** x <= b:
        if 10 ** (x + 1) <= a:
            x += 1
            continue
        mn = max(10 ** x, a)
        mx = min(10 ** (x + 1) - 1, b)
        u = str(mn)
        v = str(mx)
        assert len(u) == len(v) == x + 1
        x += 1
        c += match_between(stored, auto, init, u, v)
    print(c)
    
    
