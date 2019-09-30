from fractions import Fraction

def reader(inFile):
    (N,F) = inFile.getWords()
    N = int(N)
    F = Fraction(F)
    return (N, F, inFile.readline())

def solver((N,F,word)):
    t = [0] * (N + 1)
    for i in xrange(N):
        t[i + 1] = t[i] + int(word[i])
    rec = (2, 0)
    for j in xrange(1,N+1):
        for i in xrange(j):
            ratio = Fraction(t[j]-t[i], j-i)
            scr = (abs(ratio-F), i)
            if scr < rec:
                rec = scr
    return rec[1]

if __name__ == "__main__":
    # GCJ library publically available at http://ideone.com/2PcmZT
    from GCJ import GCJ
    GCJ(reader, solver, r"C:\gcj\finals\c", "c").run()
