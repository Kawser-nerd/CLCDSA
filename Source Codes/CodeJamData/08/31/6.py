def solve():
    f = open('A-large.in')
    g = open('A.out','w')
    N = int(f.readline())
    for i in range(N):
        P, K, L = map(int,f.readline().split())
        ns = map(int,f.readline().split())
        ns.sort()
        ns.reverse()
        print ns
        kk = []
        c = 0
        t = 0
        while c<L :
            kk.append(1+t/K)
            t+=1
            c+=1
        ret = 0
        for j in xrange(len(ns)):
            ret += kk[j]*ns[j]
        g.write('Case #%d: %d\n' % (i+1, ret))
    g.close()
solve()