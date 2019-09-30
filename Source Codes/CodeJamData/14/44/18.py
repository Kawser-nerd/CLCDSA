def nonEmptySplitting(els, k, found_cb, i=0, cur=[]):
    if i == len(els):
        for l in range(k):
            if not l in cur:
                return
        found_cb(cur)
    else:
        for l in range(k):
            cur.append(l)
            nonEmptySplitting(els, k, found_cb, i+1, cur)
            cur.pop(-1)

def nodeCnt(strs):
    prefs = set()
    for s in strs:
        for i in range(0, len(s)+1):
            prefs.add(s[:i])
    return len(prefs)

def solve(setCnt, strs):
    bestNc = [0]
    cases = [0]

    def found_cb(part):
        nc = 0
        for i in range(setCnt):
            servStrs = [strs[j]
                           for j in range(len(strs))
                           if i == part[j]]
            ncinc = nodeCnt(servStrs)
            #print servStrs, ncinc
            nc += ncinc

        #print part, nc
        if nc > bestNc[0]:
            bestNc[0] = nc
            cases[0] = 1
        elif nc == bestNc[0]:
            cases[0] += 1

    nonEmptySplitting(strs, setCnt, found_cb)

    return '{} {}'.format(bestNc[0], cases[0] % 1000000007)

#print nodeCnt(["AAA", "AAB", "AB", "B"])

import sys
infname = sys.argv[1]
with open(infname) as inf:
    with open(infname.replace('.in', '.out'), 'w') as outf:
        T = int(inf.readline())
        for t in range(1, T+1):
            n, servs = map(int, inf.readline().split())
            words = [inf.readline().strip() for _ in range(n)]
            outf.write('Case #{}: {}\n'.format(t,solve(servs, words)))