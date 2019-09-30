def parse(inFile):
    n = inFile.getInt()
    return (n, inFile.getInts(), inFile.getInts())

def solve((n, ls, ps)):
    mx = max([3]+[float(ls[i])/ps[i] for i in xrange(n) if ps[i] != 0]) + 1
    x = [(float(ls[i])/ps[i] if ps[i] != 0 else mx,i) for i in xrange(n)]
    return str(" ".join([str(z[1]) for z in sorted(x)]))

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(parse, solve, "/Users/lpebody/gcj/2012_3/a/", "A").run()

            
