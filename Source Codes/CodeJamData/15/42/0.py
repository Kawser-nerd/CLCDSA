T = int( input() )

for test in range(1,T+1):
    N, V, X = input().split()
    N = int(N)
    goalV = int( float(V)*10000 + 0.5 )
    goalT = int( float(X)*10000 + 0.5 )

    vody = [ [ int( float(x)*10000 + 0.5 ) for x in input().split() ] for n in range(N) ]
    vody = [ (temp,rate) for rate,temp in vody ]
    vody.sort()
    if N == 2 and vody[0][0] == vody[1][0]:
        N = 1
        vody = [ ( vody[0][0], vody[0][1] + vody[1][1] ) ]

    if vody[0][0] > goalT:
        print('Case #{}: IMPOSSIBLE'.format(test))
        continue

    if vody[-1][0] < goalT:
        print('Case #{}: IMPOSSIBLE'.format(test))
        continue

    if vody[0][0] == goalT:
        print('Case #{}: {:.12f}'.format( test, 1. * goalV / vody[0][1] ))
        continue

    if vody[-1][0] == goalT:
        print('Case #{}: {:.12f}'.format( test, 1. * goalV / vody[-1][1] ))
        continue

    assert N == 2
    assert vody[0][0] < goalT < vody[1][0]

    p0 = goalT - vody[0][0]
    p1 = vody[1][0] - goalT

    v0 = 1. * goalV * p1 / (p0+p1)
    v1 = 1. * goalV * p0 / (p0+p1)

    t0 = 1. * v0 / vody[0][1]
    t1 = 1. * v1 / vody[1][1]
    
    print('Case #{}: {:.12f}'.format( test, max(t0,t1) ))
