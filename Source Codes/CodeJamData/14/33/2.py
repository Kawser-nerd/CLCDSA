def reader(inFile):
   return tuple(inFile.getInts())

from itertools import combinations

def solver((N,M,K)):
    points = [(i,j) for i in xrange(N) for j in xrange(M)]
    rec = 0
    for sets in combinations(points, K):
        v = set(sets)
        scr = len([z for z in v if len([1 for (a,b) in [(-1,0),(1,0),(0,-1),(0,1)] if (z[0]+a,z[1]+b) in v]) == 4])
        if scr > rec:
            rec = scr
    return K - rec

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/luke/gcj/2014/1c/c", "c").run()
