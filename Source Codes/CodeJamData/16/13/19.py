def longestdfs(inedges, start, seen):
    seen.add(start)
    # guaranteed to have no cycles
    if not inedges[start]:
        return 1
    candidates = []
    for inedge in inedges[start]:
        candidates.append(longestdfs(inedges, inedge, seen))
    return max(candidates) + 1

cases = int(input())

for case in range(cases):
    n = int(input())
    toedges = [int(x) - 1 for x in input().split()]
    inedges = [[] for x in toedges]
    for i, to in enumerate(toedges):
        inedges[to].append(i)

    # find mutual
    mutuals = []  # (a, b)
    for i, to in enumerate(toedges):
        if toedges[to] == i and to > i:
            mutuals.append((to, i))
            inedges[to].remove(i)
            inedges[i].remove(to)
    # convert mutuals to list of ints, representing depth
    mdepths = []
    seen = set()
    for a, b in mutuals:
        # dfs from a and dfs from b
        mdepths.append(longestdfs(inedges, a, seen) + longestdfs(inedges, b, seen))
    # guaranteed that cycles are not in mutuals
    cyclemax = 0
    for i in range(n):
        if i in seen:
            continue
        # go through the cycle
        seen.add(i)
        length = 1
        tempi = toedges[i]
        path = [i, tempi]
        while tempi != i:
            if tempi in seen:
                # tempi MUST be in there somewhere.
                # print("before", length)
                length -= path.index(tempi)
                # print("after", length)
                break
            seen.add(tempi)
            length += 1
            tempi = toedges[tempi]
            path.append(tempi)
        # print("we got a cycle of length", length)
        cyclemax = max(length, cyclemax)
    ans = max(sum(mdepths), cyclemax)

    print("Case #{}: {}".format(case+1, ans))
