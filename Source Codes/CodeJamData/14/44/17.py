import itertools

def trie(S):
    X = {}
    n = 1
    for s in S:
        p = X
        for c in s:
            if c not in p:
                p[c] = {}
                n += 1
            p = p[c]
    return n

for test in range(input()):
    M, N = map(int, raw_input().split())
    S = [raw_input() for _ in range(M)]
    X, Y = 0, 0

    for P in itertools.product(range(N), repeat=M):
        T = [[] for _ in range(N)]
        for i in range(M):
            T[P[i]] += [S[i]]
        if min(len(t) for t in T)==0:
            continue
        x = sum(trie(t) for t in T)
        if x>X:
            X = x
            Y = 0
        if x==X:
            Y += 1

    print "Case #%s: %s %s" % (test+1, X, Y)
