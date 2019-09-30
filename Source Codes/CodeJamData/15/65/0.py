def reader(inFile):
    (N,M) = tuple(inFile.getInts())
    spells = [tuple(inFile.getInts()) for j in xrange(N)]
    return (N,M,spells)

from fractions import gcd

def f(spells):
    score = 0
    for z in spells:
        h = 0
        v = 0
        for m in z:
            v += m
            if v > h:
                h = v
        score += h
    return score

from itertools import permutations

def solver((N,M,spells)):
    spells = [z for z in spells if max(z) > 0]
    if len(spells) == 0:
        return 0
    started = False
    rec = 0
    for v in permutations(range(M)):
        scr = f([[z[i] for i in v] for z in spells])
        if (started == False):
            started = True
            rec = scr
        else:
            rec = max(rec, scr)
    return rec

if __name__ == "__main__":
    # GCJ library publically available at http://ideone.com/2PcmZT
    from GCJ import GCJ
    GCJ(reader, solver, r"C:\gcj\finals\e", "e").run()
