# maximize number of kits formed from packages
# each kit contains exactly one of each ingredient
# so question is how to match ingredients together maximally
# each ingredient must be between 90% and 110% of number of servings in package
# greedy algorithm suggests sorting all ingredients first??
# can also bucket packages by how many servings it could do

# ugh, legal ranges start to overlap once you get above 10 servings per kit
# think instead about what's the legal range of kit quantities for a given
# ingredient amount, then maybe we can apply greedy approach

import math

def iceil(p, q):
    assert p >= 0
    assert q > 0
    if p == 0:
        return 0
    else:
        return (p - 1) / q + 1

def ifloor(p, q):
    assert p >= 0
    assert q > 0
    return p / q

def solve(recipe, packages):
    # recipe[i] = number of grams of ingredient i in 1 serving of ratatouille
    # packages[i][j] = number of grams in package j of ingredient i

    ni = len(recipe)
    np = len(packages[0])

    vrs = [[] for i in xrange(ni)]
    for i in xrange(ni):
        for p in xrange(np):
            w = packages[i][p]
            rw = recipe[i]
            # 0.9 * rw * n <= w
            # n <= w / (0.9 * rw)
            #nlo = int(math.ceil(w / (1.1 * rw)))
            nlo = iceil(w * 10, rw * 11)
            #nhi = int(math.floor(w / (0.9 * rw)))
            nhi = ifloor(w * 10, rw * 9)
            if nlo <= nhi:
                vrs[i].append((nlo, nhi, w))
        vrs[i].sort()
    result = 0
    while all(vr for vr in vrs):
        max_nlo = max(vr[0][0] for vr in vrs)
        min_nhi = min(vr[0][1] for vr in vrs)
        if max_nlo <= min_nhi: # all overlap?
            ws = []
            for vr in vrs:
                ws.append(vr[0][2])
                vr.pop(0)
            result += 1
        else:
            # some nlo > other nhi
            for vr in vrs:
                while vr and max_nlo > vr[0][1]:
                    vr.pop(0)
    return result

if __name__ == '__main__':
    import sys
    fp = open(sys.argv[1])
    def readline():
        return fp.readline().strip()
    num_cases = int(readline())
    for c in xrange(num_cases):
        ni, np = [int(x) for x in readline().split()]
        recipe = [int(x) for x in readline().split()]
        packages = []
        for i in xrange(ni):
            packages.append([int(x) for x in readline().split()])
        print "Case #%d: %d" % (c + 1, solve(recipe, packages))
