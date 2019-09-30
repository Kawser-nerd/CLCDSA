IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    N = int(IN.readline())
    
    while True:
        l = [int(c) for c in str(N)]
        for i in xrange(len(l)-1):
            if l[i] > l[i+1]:
                N = int(str(N)[:i+1] + '0' * (len(l)-i-1)) - 1
                break
        else:
            break
    
    OUT.write('Case #{}: {}\n'.format(test+1, N))
    print test+1, N

IN.close()
OUT.close()
