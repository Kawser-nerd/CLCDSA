import sys

T = int(sys.stdin.readline())

for case in range(T):
    N = int(sys.stdin.readline())
    fsp = map(int, sys.stdin.readline().strip().split())
    fs = {}
    for i in range(len(fsp)):
        fs[i+1] = fsp[i]
    # print "fs", fs

    hits = {}
    for i in fs:
        if not i in hits:
            hits[i] = 0
        if fs[i] in hits:
            hits[fs[i]] += 1
        else:
            hits[fs[i]] = 1
    # print "hits", hits

    # Find 2-cycles
    tc = set([]) # 1-indexed (Student IDs)
    tcEntries = {}
    for i in fs:
        if fs[fs[i]] == i:
            tc.add(i)
            tcEntries[i] = []

    cycles = {}

    # Leaves
    heights = {}
    for i in fs:
        if hits[i] == 0: # Leaf!
            cur = i
            seen = set([cur])
            heights[cur] = 1
            height = 1
            while True:
                # print cur, height
                n = fs[cur]
                if n in cycles: # hit existing cycle - dont care
                    break
                if n in tc: # hit a two-cycle
                    tcEntries[n].append((height, cur))
                    break
                if n in seen: # made a cycle
                    cyc = heights[cur] - heights[n] + 1
                    cycles[n] = cyc
                    # print "cycle", n, cyc
                    for j in range(cyc):
                        n = fs[n]
                        cycles[n] = cyc
                    break
                if n in heights: # found existing tree
                    if heights[n] >= height+1:
                        break
                height += 1
                heights[n] = height
                cur = n
                seen.add(cur)

    # Cycle detect lone cycles
    for i in fs:
        if i in tc: continue
        if hits[i] != 0:
            cur = i
            start = i
            length = 1
            seen = set([])
            found = False
            while True:
                n = fs[cur]
                if n == start:
                    found = True
                    break
                if n in seen:
                    break
                seen.add(n)
                length += 1
                cur = n
            if found:
                for j in range(length):
                    cur = fs[cur]
                    cycles[cur] = length

    # print "heights", heights
    # print "cycles", cycles
    # print "tcEntries", tcEntries
    # print

    bestCycle = 0
    if len(cycles) > 0:
        bestCycle = max(cycles.values())
    sumTwoCycles = 0
    while len(tc) > 0:
        tleft = next(iter(tc))
        left = 0
        for j in tcEntries[tleft]:
            if j[0] > left:
                left = j[0]
        tright = fs[tleft]
        right = 0
        for j in tcEntries[tright]:
            if j[0] > right:
                right = j[0]
        tc.remove(tright)
        tc.remove(tleft)
        # print "tc add:", tleft, "(%d)"%(left), tright, "(%d)"%(right)
        sumTwoCycles += left + right + 2
    # print "bestCycle", bestCycle
    # print "sumTwoCycles", sumTwoCycles
    print "Case #%d: %d" % (case+1, max(bestCycle, sumTwoCycles))
    continue
