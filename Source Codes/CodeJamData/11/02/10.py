infile = "B-large.in"

debug = False

def solve(instr):
    data = instr.split()
    C = int(data[0])
    D_ix = 1+C
    C_strs = data[1:D_ix]
    assert len(C_strs) == C
    D = int(data[D_ix])
    N_ix = D_ix+1+D
    assert N_ix + 2 == len(data)
    D_strs = data[D_ix+1:N_ix]
    assert len(D_strs) == D
    N = int(data[N_ix])
    N_str = data[N_ix+1]
    assert len(N_str) == N

    if debug:
        print "Input: %s" % [C, C_strs, D, D_strs, N, N_str]

    opposed = {}
    for d in D_strs:
        assert len(d) == 2
        
        L = opposed.get(d[0], [])
        L.append(d[1])
        opposed[d[0]] = L

        if d[0] != d[1]:
            L = opposed.get(d[1], [])
            L.append(d[0])
            opposed[d[1]] = L
        
    if debug:
        print "Opposed: %s" % opposed

    combined = {}
    for c in C_strs:
        assert len(c) == 3

        M = combined.get(c[0], {})
        assert c[1] not in M
        M[c[1]] = c[2]
        combined[c[0]] = M

        if c[0] != c[1]:
            M = combined.get(c[1], {})
            assert c[0] not in M
            M[c[0]] = c[2]
            combined[c[1]] = M

    if debug:
        print "Combined: %s" % combined

    elements = []
    for n in N_str:
        if debug:
            print "%s    <-- %s" % (elements, n)
        if len(elements) == 0:
            elements.append(n)
            if debug: print "  Empty string, auto-add"
            continue
        prev = elements[-1]
        try:
            new = combined[n][prev]
            elements[-1] = new
            if debug: print "  Combined %s %s --> %s" % (prev, n, new)
            continue
        except KeyError:
            pass

        clear = False
        deadly = opposed.get(n)
        if deadly is not None:
            for e in elements:
                if e in deadly:
                    clear = True
                    break

        if clear:
            elements = []
            if debug: print "  Opposed elements; clearing."
        else:
            elements.append(n)
            if debug: print "  No interaction; adding %s" % n
            

    return "[" + ", ".join(elements) + "]"
        
def main():
    i = file(infile)
    N = int(i.readline())
    for n in xrange(N):
        soln = solve(i.readline())
        print "Case #%d: %s" % (n+1, soln)
        
main()
