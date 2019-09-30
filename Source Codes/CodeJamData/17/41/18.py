IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    N, P = map(int,IN.readline().split())
    G = [0] * P 
    for g in map(int, IN.readline().split()):
        G[g % P] += 1
    
    if P == 2:
        answer = N - G[1] / 2
    elif P == 3:
        if G[1] >= G[2]:
            answer = G[0] + G[2] + (G[1] - G[2] + 2) / 3
        else:
            answer = G[0] + G[1] + (G[2] - G[1] + 2) / 3
    elif P == 4:
        if G[3] > G[1]:
            G[1], G[3] = G[3], G[1]
        answer = G[0] + G[2]/2 + G[3]
        G[2] -= (G[2]/2) * 2
        G[1] -= G[3]
        while G[1] >= 2 and G[2] >= 1:
            answer += 1
            G[1] -= 2
            G[2] -= 1
        answer += G[1] / 4
        G[1] -= (G[1]/4) * 4
        if G[1] + G[2] > 0:
            answer += 1        
    
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer
    
IN.close()
OUT.close()
