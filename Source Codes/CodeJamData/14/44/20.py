t = int(raw_input())

def calcnodes(L):
    d = {}
    for w in L:
        for i in range(len(w) + 1):
            d[w[:i]] = 1
    return len(d)

def extract(ids, L):
    if (len(ids) == 0):
        return []
    val = extract(ids[1:], L)
    val.append(L[ids[0]])
    return val

def check(part, L):
    val = 0
    for p in part:
        val += calcnodes(extract(p, L))
    return val

def solve(cas):
    m, n = tuple(map(int, raw_input().split()))
    L = []
    for i in range(m):
        L.append(raw_input())

    worst = 0
    count = 0

    for mask in range(n ** m):
        part = []
        for j in range(n):
            part.append([])
        for j in range(m):
            part[mask%n].append(j)
            mask /= n
        val = check(part, L)
        if val > worst:
            worst = val
            count = 1
        elif val == worst:
            count += 1

    print "Case #%s: %s %s" % (cas, worst, count)

    """
    partitions = [[[],[],[],[]]]
    for val in range(len(L)):
        npartitions = []
        for part in partitions:
            for j in len(part):
                npart = part[:]
                npart[j].append(val)
                npartitions.append(npart)
    """

for i in range(t):
    solve(i+1)
