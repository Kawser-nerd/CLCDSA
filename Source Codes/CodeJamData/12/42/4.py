def parse(inFile):
    return (tuple(inFile.getInts()+[inFile.getInts()]))

def solve((N,W,L,rs)):
    xs = [(rs[i],i) for i in xrange(N)]
    xs.sort()
    coords = [(-1,-1) for i in xrange(N)]
    lhs = [(0,0),(0,L)]
    for (r,i) in xs[::-1]:
        for z in xrange(len(lhs)):
            m = lhs[z]
            if m[0] == 0 or (m[0] + r) <= W:
                cx = 0 if (m[0] == 0) else (m[0] + r)
                cy = 0 if (m[1] == 0) else (lhs[z - 1][1] + r)
                if (cy > L):
                    print "BANG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                    return "oops"
                coords[i] = (cx,cy)
                z2 = z + 1
                while (z2 < len(lhs)) and (lhs[z2][1] <= cy + r):
                    z2 += 1
                lhs = [v for v in lhs if v[0] >= cx + r] + ([(cx+r,0)] if cy == 0 else []) + [(cx + r, cy + r)] + [v for v in lhs if v[1] > cy + r]
                break
        if (coords[i] == (-1,-1)):
            print "BANG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
            return "oops"
    return " ".join([str(d) for c in coords for d in c])

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(parse, solve, "/Users/lpebody/gcj/2012_2/b", "B").run()

            
