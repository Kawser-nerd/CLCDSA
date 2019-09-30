# Gorosort Google Code Jam
# zbanks Zach Banks zach@zbanks.net
# Python


# Thanks stackoverflow!
# http://stackoverflow.com/questions/2987605/minimum-number-of-swaps-needed-to-change-array-1-to-array-2
# via determine number of swaps sort array
# Modified heavily to return cycles

def get_permutation(L1, L2):
    if sorted(L1) != sorted(L2):
        raise ValueError("L2 must be permutation of L1 (%s, %s)" % (L1,L2))

    permutation = map(dict((v, i) for i, v in enumerate(L1)).get, L2)
    assert [L1[p] for p in permutation] == L2
    return permutation

def get_cycles(permutation):
    # decompose the permutation into disjoint cycles
    nswaps = 0
    seen = set()
    cycles = []
    for i in xrange(len(permutation)):
        if i not in seen:           
           j = i # begin new cycle that starts with `i`
           cycles.append([i+1])
           while permutation[j] != i:
               j = permutation[j]
               seen.add(j)
               nswaps += 1
               cycles[-1].append(j+1)
    return cycles

def main():
    f = open("input.txt")
    testlen = int(f.readline().strip())
    tests = []
    i = 0
    for line in f:
        if i % 2:
            tests.append(line.strip())
        i += 1

    tests = tests[:testlen]

    for test, i in zip(tests, range(testlen)):
        print "Case #%d: %s" % (i+1, solve(parse(test)))

def parse(test):
    return map(int, test.split(" "))

def solve(test):
    perm = get_permutation(test, sorted(test))
    #print test, sorted(test), number_of_swaps(perm), "\n", perm
    cycles = get_cycles(perm)
    v = 0
    for cy in cycles:
        if len(cy) > 1:
            v += len(cy)
    return "%d.000000" % (v)

if __name__ == "__main__":
    main()
