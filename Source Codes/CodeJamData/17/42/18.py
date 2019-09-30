IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    N, C, M = map(int,IN.readline().split())
    
    T = [[0] * N for _ in xrange(C)]
    
    for i in xrange(M):
        p, b = map(int,IN.readline().split())
        T[b-1][p-1] += 1
        
    SumForC = [sum(t) for t in T]
    SumForP = [sum([t[i] for t in T]) for i in xrange(N)]
    CumForP = [0] * N
    CumForP[0] = SumForP[0]
    for i in xrange(1, N):
        CumForP[i] = CumForP[i-1] + SumForP[i]
    for i in xrange(0, N):
        CumForP[i] += i
        CumForP[i] /= i+1

    best = max(max(SumForC), max(CumForP))
    promotion = 0
    for i in xrange(1, N):
        promotion += max(0, SumForP[i] - best)
    
    OUT.write('Case #{}: {} {}\n'.format(test+1, best, promotion))
    print test+1, best, promotion

IN.close()
OUT.close()
