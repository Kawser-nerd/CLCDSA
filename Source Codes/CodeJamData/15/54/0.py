# Linguo entry for Problem D in 2015 Google Code Jam Round 3 'The Battle for Seattle'

from collections import defaultdict

def reader(inFile):
    P = inFile.getInt()
    Es = inFile.getInts()
    Fs = inFile.getInts()
    return (P, Es, Fs)

def exists(it):
    for z in it:
        return True
    return False

b2lc = {1 << i:i for i in xrange(64)}

def b2log(n):
    return b2lc[n]

def solver((P, Es, Fs)):
    G = {Es[i]-Es[0]:Fs[i] for i in xrange(P)}
    k = len(G) - 1
    v = []
    nums = [Es[i]-Es[0] for i in xrange(P-1,-1,-1)]
    goal = -Es[0]
    G2 = {a:b for (a,b) in G.items()}
    while len(G) > 1:
        Gk = sorted(G.keys())
        num = Gk[1]
        v.append(num)
        for i in Gk:
            if (i + num) in G:
                G[i + num] -= G[i]
            else:
                G[i + num] = -G[i]
        G = {a:b for (a,b) in G.items() if b != 0}
    v = [0] * b2log(G[0]) + v
    w = []
    for num in v[::-1]:
        for i in sorted(G2.keys()):
            if (i + num) in G2:
                G2[i + num] -= G2[i]
            else:
                G2[i + num] = -G2[i]
        G2 = {a:b for (a,b) in G2.items() if b != 0}
        if goal - num in G2:
            w.append(-num)
            goal -= num
        else:
            w.append(num)
    w = sorted(w)
    return " ".join(str(k) for k in w)

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/luke/gcj/2015/3/d/", "d").run()
