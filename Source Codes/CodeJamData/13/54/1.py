def reader(inFile):
    return inFile.readline()

from sys import stderr

def solver(gonds):
    n = len(gonds)
    k = sum([1 << i for i in xrange(n) if gonds[i] == "X"])
    exps = [0.0] * (1 << n)
    for i in xrange((1 << n) - 2, -1, -1):
        if (i & k) == k:
            tot = 0
            for j in xrange(n):
                pay = n
                w = j
                while ((i >> w) & 1) == 1:
                    w = (w + 1) % n
                    pay -= 1
                tot += (pay + exps[i + (1 << w)])
            exps[i] = tot / n
    return exps[k]

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/lpebody/gcj/2013_3/d/", "d").run()
