IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    K, C, S = map(int,IN.readline().split())
    total = K ** C
    
    if C * S < K:
        answer = 'IMPOSSIBLE'
    else:
        answer = []
        for s in xrange(S):
            cover = list(xrange(s * C, (s+1) * C))
            for i in xrange(len(cover)):
                if cover[i] >= K:
                    cover[i] = K-1
            value = [K ** i for i in xrange(C)]
            answer.append(1 + sum([c * v for (c,v) in zip(cover, value)]))
        
        # get rid of duplicates
        answer = list(set(answer))     
            
        answer = ' '.join(map(str,answer))
    
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer

IN.close()
OUT.close()
