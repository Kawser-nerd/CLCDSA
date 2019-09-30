def solve(C, D, V):
    d = 0
    v = 0
    N = []
    while v<V:
        if d<len(D) and D[d]<=v+1:
            d += 1
        else:
            N += [v+1]
        v = (sum(D[:d])+sum(N))*C
    return len(N)

for t in range(input()):
    C,_,V = map(int, raw_input().split())
    D = map(int, raw_input().split())
    print "Case #%s: %s"%(t+1, solve(C,D,V))
