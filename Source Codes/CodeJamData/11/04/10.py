infile = "D-large.in"

debug=False

def find_subsets(L):
    used = [False] * len(L)
    subsets = []
    for ix in xrange(len(L)):
        if used[ix]:
            continue
        
        used[ix] = True
        ix_subset = [ix]
        next_ix = L[ix] - 1
        while next_ix != ix:
            ix_subset.append(next_ix)
            used[next_ix] = True
            next_ix = L[next_ix] - 1
        subsets.append(ix_subset)
    assert False not in used
    assert sum(map(len, subsets)) == len(L)
    return subsets
            

def how_many(set_size):
    if set_size == 1:
        return 0
    else:
        return set_size

def solve(nstr, data):
    N = int(nstr)
    data = map(int, data.split())
    assert len(data) == N

    subsets = find_subsets(data)
    if debug:
        print subsets
        print map(len, subsets)

    avg = 0.0
    for subset in subsets:
        avg += how_many(len(subset))

    return "%.7f" % avg

def main():
    i = file(infile)
    N = int(i.readline())
    for n in xrange(N):
        soln = solve(i.readline(), i.readline())
        print "Case #%d: %s" % (n+1, soln)

main()

