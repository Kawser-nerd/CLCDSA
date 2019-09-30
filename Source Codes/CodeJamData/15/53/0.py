# Linguo entry for Problem c in 2015 Google Code Jam Round 3 'The Battle for Seattle'

def reader(inFile):
    (Y, N) = inFile.getInts()
    Ps = inFile.getInts()
    Ss = inFile.getInts()
    return (Y, N, Ps, Ss)

def solve((freeMask, loc, time), Y, N, Ps, Ss, tv):
    if freeMask == 0:
        return time
    if (tv != -1) and time > tv:
        return tv
    nextLeft = (-1,-1,-1)
    nextRight = (-1,-1,-1)
    for j in xrange(N):
        if (freeMask >> j) & 1:
            if Ps[j] > 0:
                t = float((Ps[j] + Ss[j] * time) - loc) / (Y - Ss[j])
                l = loc + Y * t
                if nextRight[0] == -1 or nextRight[2] > time + t:
                    nextRight = (freeMask ^ (1 << j),l,time+t)
            else:
                t = float((Ps[j] - Ss[j] * time) - loc) / (Ss[j] - Y)
                l = loc - Y * t
                if nextLeft[0] == -1 or nextLeft[2] > time + t:
                    nextLeft = (freeMask ^ (1 << j),l,time+t)
    if nextLeft[0] == -1:
        return solve(nextRight, Y, N, Ps, Ss, tv)
    elif nextRight[0] == -1:
        return solve(nextLeft, Y, N, Ps, Ss, tv)
    scl = solve(nextLeft, Y, N, Ps, Ss, tv)
    if (tv == -1) or (scl < tv):
        tv = scl
    return min(scl, solve(nextRight, Y, N, Ps, Ss, tv))

def solver((Y, N, Ps, Ss)):
    return solve(((1<<N)-1,0,0),Y,N,Ps,Ss,-1)

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/luke/gcj/2015/3/c/", "c").run()
