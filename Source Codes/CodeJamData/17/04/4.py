N = 0

def match(S, D):
    INF = 9999
    StoD = [INF] * len(S)
    DtoS = [INF] * len(D)
    seenS = set()
    
    def search(pathS, pathD):
        i = pathS[-1]
        if i in seenS:
            return None
        seenS.add(i)
        s = S[i]
        
        for j, d in enumerate(D):
            if StoD[i] == j:
                continue
            if (s+d) % 2 == 0 and 1 <= (s+d)/2 <= N and 1 <= (s-d)/2 <= N:
                if DtoS[j] == INF:
                    return pathS, pathD + [j]
                else:
                    path = search(pathS + [DtoS[j]], pathD + [j])
                    if path is not None:
                        return path
        return None
    
    while True:
        seenS = set()
        for i, s in enumerate(S):
            if StoD[i] != INF:
                continue
            path = search([i], [])
            if path is not None:
                for i, j in zip(path[0], path[1]):
                    StoD[i] = j
                    DtoS[j] = i
                break
        else:
            break
    return {((S[i]+D[j])/2, (S[i]-D[j])/2) for i, j in enumerate(StoD) if j != INF}

IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    rook = set()
    bishop = set()
    N, M = map(int,IN.readline().split())
    for _ in xrange(M):
        sym, x, y = IN.readline().split()
        x, y = int(x), int(y)
        if sym != '+':
            rook.add((x, y))
        if sym != 'x':
            bishop.add((x, y))
    
    # solve rook
    rows = list({x for x in xrange(1, N+1)} - {c[0] for c in rook})
    cols = list({y for y in xrange(1, N+1)} - {c[1] for c in rook})
    newRook = {(x, y) for x, y in zip(rows, cols)}
    
    # solve bishop
    bishopS = list({s for s in xrange(2, 2*N+1)} - {c[0] + c[1] for c in bishop})
    bishopD = list({d for d in xrange(-N+1, N)} - {c[0] - c[1] for c in bishop})
    newBishop = match(bishopS, bishopD)
    
    # make output
    score = len(rook) + len(bishop) + len(newRook) + len(newBishop)
    count = len(newRook | newBishop)
    OUT.write('Case #{}: {} {}\n'.format(test+1, score, count))
    print test+1, score, count
    for x, y in newBishop - newRook:
        if (x, y) in rook:
            OUT.write('o {} {}\n'.format(x, y))
        else:
            OUT.write('+ {} {}\n'.format(x, y))
    for x, y in newRook - newBishop:
        if (x, y) in bishop:
            OUT.write('o {} {}\n'.format(x, y))
        else:
            OUT.write('x {} {}\n'.format(x, y))
    for x, y in newRook & newBishop:
        OUT.write('o {} {}\n'.format(x, y))

IN.close()
OUT.close()
