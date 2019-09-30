T = int( input() )
for t in range(1,T+1):
    D = int( input() )
    P = [ int(x) for x in input().split() ]
    best = min( zeru + sum( (p-1)//zeru for p in P ) for zeru in range(1,max(P)+1) )
    print('Case #{}: {}'.format(t,best))
