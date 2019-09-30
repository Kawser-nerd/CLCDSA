dirs = { '^': (-1,0), 'v': (1,0), '<': (0,-1), '>': (0,1) }

def has_another(mapa, r, c, dr, dc):
    R, C = len(mapa), len(mapa[0])
    while True:
        r += dr
        c += dc
        if r < 0 or r >= R or c < 0 or c >= C: return False
        if mapa[r][c] != '.': return True

T = int( input() )
for test in range(1,T+1):
    R, C = [ int(x) for x in input().split() ]
    mapa = [ [ z for z in input() ] for r in range(R) ]

    answer = 0
    impossible = False
    for r in range(R):
        for c in range(C):
            if mapa[r][c] == '.': continue
            dr, dc = dirs[ mapa[r][c] ]
            if has_another( mapa, r, c, dr, dc ): continue 
            can_save = False
            for x in dirs:
                dr, dc = dirs[x]
                if has_another( mapa, r, c, dr, dc ): can_save = True
            if can_save:
                answer += 1
            else:
                impossible = True

    if impossible:
        print('Case #{}: IMPOSSIBLE'.format(test))
    else:
        print('Case #{}: {}'.format(test,answer))

