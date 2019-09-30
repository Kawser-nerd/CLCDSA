from collections import defaultdict

IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    N, K = map(int,IN.readline().split())
    
    queue = defaultdict(int)
    queue[N] = 1
    
    sizes = []
    binN = '{:b}'.format(N)
    for i in xrange(1, len(binN)+1):
        sizes.append(int(binN[:i], 2)-1)
        sizes.append(int(binN[:i], 2))
    sizes = sizes[::-1]
    
    for chunkSize in sizes:
        chunkNum = queue[chunkSize]
        minNext = (chunkSize - 1) / 2
        maxNext = (chunkSize - 1) - minNext
        # print chunkSize, chunkNum, minNext, maxNext, K
        
        if K <= chunkNum:
            answer = (maxNext, minNext)
            break
        K -= chunkNum
        
        if maxNext == minNext:
            queue[maxNext] += 2 * chunkNum
        else:
            queue[maxNext] += chunkNum
            queue[minNext] += chunkNum
    
    OUT.write('Case #{}: {} {}\n'.format(test+1, answer[0], answer[1]))
    print test+1, answer

IN.close()
OUT.close()
