def iceil(num,den): return (num+den-1) // den

T = int( input() )
for t in range(1,T+1):
    N, P = [ int(_) for _ in input().split() ]
    R = [ int(_) for _ in input().split() ]
    Q = [ [ int(_) for _ in input().split() ] for n in range(N) ]
    for n in range(N):
        Q[n].sort()
    LO = [ [] for n in range(N) ]
    HI = [ [] for n in range(N) ]
    for n in range(N):
        for p in range(P):
            LO[n].append( iceil(10*Q[n][p],11*R[n]) )
            HI[n].append( (10*Q[n][p]) // (9*R[n]) )
    for n in range(N):
        for p in range(P):
            if LO[n][p] == 0:
                LO[n][p] = 1

    BUILT = 0
    first = [ 0 for n in range(N) ]
    while max(first) < P:
        chcem = max( LO[n][first[n]] for n in range(N) )
        dobre = True
        for n in range(N):
            if chcem > HI[n][first[n]]:
                dobre = False
                first[n] += 1
        if dobre:
            BUILT += 1
            for n in range(N):
                first[n] += 1
    
    print('Case #{}: {}'.format(t,BUILT))
