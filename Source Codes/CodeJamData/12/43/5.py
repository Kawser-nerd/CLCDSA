# peak j looks the biggest if x[j] - x[i] / (j - i) = max ( x[k] - x[i] / (k - i), k > i) and j is the smallest k equalling it

from fractions import Fraction

def parse(inFile):
    return (inFile.getInt(), [z - 1 for z in inFile.getInts()])

def whatis(N, hs):
    xs = []
    for i in xrange(N - 1):
        rec = i + 1
        for j in xrange(i + 2, N):
            if (hs[j] - hs[i]) * (rec - i) > (hs[rec] - hs[i]) * (j - i):
                rec = j
        xs += [rec]
    return xs

def solve((N, xs)):
    for j in xrange(N - 1):
        for k in xrange(j + 1, xs[j]):
            if xs[k] > xs[j]:
                return "Impossible"
    inwayofs = [0] * N
    for j in xrange(N - 1):
        for k in xrange(j + 1, xs[j]):
            inwayofs[k] += 1
    # print xs
    # print inwayofs
    numtoplace = N - 1
    hs = [-1] * N
    hs[N - 1] = 10 ** 9
    height = 10 ** 9
    while numtoplace > 0:
        # print hs, inwayofs
        place = [i for i in xrange(N - 1) if hs[i] == -1 and inwayofs[i] == 0]
        for p in place[::-1]:
            if (xs[p] < N - 1) and Fraction(hs[xs[p]] - height, xs[p] - p) < Fraction(hs[xs[xs[p]]] - height, xs[xs[p]] - p):
                # print p, xs[p], xs[xs[p]], height, hs[xs[p]], hs[xs[xs[p]]]
                height = ((hs[xs[p]]) * (xs[xs[p]] - p) - hs[xs[xs[p]]] * (xs[p] - p)) / (xs[xs[p]] - xs[p])
                # height = (hs[xs[p]] - (((p - xs[p]) * (hs[xs[xs[p]]] - hs[xs[p]])) / (xs[xs[p]] - xs[p]))) - 2
                # print p, xs[p], xs[xs[p]], height, hs[xs[p]], hs[xs[xs[p]]]
            hs[p] = height
            numtoplace -= 1
            for k in xrange(p + 1, xs[p]):
                inwayofs[k] -= 1
        height -= 1
    if xs != whatis(N, hs):
        print "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        print str(xs) + " vs " + str(whatis(N,hs))
    return " ".join(["%d" % h for h in hs])

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(parse, solve, "/Users/lpebody/gcj/2012_2/c", "C").run()

# x[0] = k => x[1]...x[k-1] <= k
# x[k] = 
