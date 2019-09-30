
#p1

def solve(N):
    saw = set()
    ct = 0
    A = N
    while len(saw) < 10 and ct < 100:
        ct += 1
        for x in `A`: saw.add(x)
        A += N
    return `A-N` if (len(saw) == 10 and ct < 100) else "INSOMNIA"


########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        N = rrI()
        zetaans = solve(N)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
