IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    pancake, K = IN.readline().split()
    pancake = [True if p == '-' else False for p in pancake]
    K = int(K)    
    
    answer = 0
    for i in xrange(len(pancake)-K+1):
        if pancake[i]:
            answer += 1
            for j in xrange(K):
                pancake[i+j] = not pancake[i+j]
    for i in xrange(len(pancake)-K+1, len(pancake)):
        if pancake[i]:
            answer = 'IMPOSSIBLE'
    
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer

IN.close()
OUT.close()
