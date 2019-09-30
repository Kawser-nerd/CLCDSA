T = int( input() )
for tc in range(1,T+1):
    N, L = [ int(x) for x in input().split() ]
    G = list( input().split() )
    B = input().strip()
    if B in G:
        print('Case #{}: IMPOSSIBLE'.format(tc))
        continue
    if L == 1:
        print('Case #{}: {} {}'.format(tc,'0','?'))
        continue
    print('Case #{}: {} {}'.format(tc,'10'*27 + '?' + '10'*27, '?'*(L-1)))
