import sys

def decode(s, base):
    c2v = {}
    res = 0
    next = 1
    for c in s:
        if not c in c2v:
            if len(c2v) < base:
                c2v[c] = next
                if next == 1:
                    next = 0
                elif next == 0:
                    next = 2
                else:
                    next += 1
            else:
                return (False, )
        dig = c2v[c]        
        res = base*res + dig
    return (True, res)
                   
# sIn = "input.txt"; sOut = "output.txt"
sIn = "A-large(2).in"; sOut = "A-large(2).out"

fIn = open(sIn, "r")
fOut = open(sOut, "w")
nT = int(fIn.readline().strip())
for t in xrange(nT):
    inp = fIn.readline().strip()
    mn = -1
    for base in xrange(2, 100):
        dRes = decode(inp, base)
        if dRes[0]:
            if mn == -1 or mn > dRes[1]:
                mn = dRes[1]
    print >>fOut, "Case #%d: %d" % (t + 1, mn)