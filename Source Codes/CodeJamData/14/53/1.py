def trans(seq):
    [a,b] = seq
    return (0 if a == 'L' else 1, int(b))

def reader(inFile):
    N = inFile.getInt()
    return [trans(inFile.readline().split()) for i in xrange(N)]

from fractions import gcd

H = []
pairs = []
rpairs = []
touched = []

def iter(i, j):
    global pairs, rpairs, touched
    if touched[i] == j:
        return False
    touched[i] = j
    for x in H[i]:
        if rpairs[x] == -1:
            pairs[i] = x
            rpairs[x] = i
            return True
    for x in H[i]:
        if iter(rpairs[x], j):
            pairs[i] = x
            rpairs[x] = i
            return True

def maxmatching(G, n0, n1):
    global H, pairs, rpairs, touched
    pairs = [-1] * n0
    rpairs = [-1] * n1
    H = G
    touched = [-1] * n0
    num = 0
    for i in xrange(n0):
        if iter(i, i):
            num += 1
    return num

from itertools import combinations

def slowsolver(observations):
    people = list(set([z[1] for z in observations if z[1] != 0]))
    possibs = set([(tuple([]),tuple([]))])
    for obs in observations:
        if obs[0] == 0:
            if obs[1] == 0:
                possibs = set([(tuple([z for z in ip if z != x]),op+(x,)) for (ip,op) in possibs for x in set(people+list(ip)+list(op)+[max((2000,)+ip+op)+1]) if x not in op])
            else:
                possibs = set([(tuple([z for z in ip if z != x]),op+(x,)) for (ip,op) in possibs for x in [obs[1]] if x not in op])
        else:
            if obs[1] == 0:
                possibs = set([(ip+(x,),tuple([z for z in op if z != x])) for (ip,op) in possibs for x in set(people+list(ip)+list(op)+[max((2000,)+ip+op)+1]) if x not in ip])
            else:
                possibs = set([(ip+(x,),tuple([z for z in op if z != x])) for (ip,op) in possibs for x in [obs[1]] if x not in ip])
        # print possibs
    if len(possibs) == 0:
        return "CRIME TIME"
    return min([len(ip) for (ip,op) in possibs])

def solver(observations):
    peoplein = {}
    peopleout = {}
    unknownsin = []
    unknownsout = []
    obsindex = 0
    for (e, p) in observations:
        obsindex += 1
        if p == 0:
            if e == 0:
                unknownsout.append(obsindex)
            else:
                unknownsin.append(obsindex)
        else:
            if e == 0:
                if p in peoplein:
                    del peoplein[p]
                    peopleout[p] = obsindex
                elif p in peopleout:
                    if max([-1]+unknownsin) > peopleout[p]:
                        takeout = min([z for z in unknownsin if z > peopleout[p]])
                        unknownsin = [z for z in unknownsin if z != takeout]
                        peopleout[p] = obsindex
                    else:
                        return "CRIME TIME"
                else:
                    peopleout[p] = obsindex
            else:
                if p in peopleout:
                    del peopleout[p]
                    peoplein[p] = obsindex
                elif p in peoplein:
                    if max([-1]+unknownsout) > peoplein[p]:
                        takeout = min([z for z in unknownsout if z > peoplein[p]])
                        unknownsout = [z for z in unknownsout if z != takeout]
                        peoplein[p] = obsindex
                    else:
                        return "CRIME TIME"
                else:
                    peoplein[p] = obsindex
    N = len(observations)
    v0 = [i for i in xrange(N) if observations[i][0] == 1]
    v1 = [i for i in xrange(N) if observations[i][0] == 0]
    n0 = len(v0)
    n1 = len(v1)
    G = [[j for j in xrange(n1) for l in [v1[j]] if l > k and ((observations[k][1] == 0) or (observations[l][1] == 0) or (observations[k][1] == observations[l][1]))] for i in xrange(n0) for k in [v0[i]]]
    #k = [[]]
    #for g in G:
    #    k += [a+[b] for a in k for b in g if b not in a]
    #return n0-max([len(z) for z in k])
    return n0-maxmatching(G,n0,n1)

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/luke/gcj/2014/3/c/", "c").run()
