IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    D, N = map(int,IN.readline().split())
    worst = 0
    for i in xrange(N):
        K, S = map(int,IN.readline().split())
        arrival = float(D - K) / S
        if arrival > worst:
            worst = arrival
    answer = D / worst
        
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer

IN.close()
OUT.close()
