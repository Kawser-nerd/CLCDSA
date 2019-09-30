IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    N = int(IN.readline())
    
    seen = dict()
    for m in xrange(1, 1000):
        s = str(N * m)
        for c in s:
            seen[c] = True
        if len(seen) == 10:
            break
    answer = N * m
    
    if N == 0: answer = 'INSOMNIA'
    
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer

IN.close()
OUT.close()
