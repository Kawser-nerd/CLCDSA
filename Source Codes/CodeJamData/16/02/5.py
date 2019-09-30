IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    stack = IN.readline()[:-1]
    stack += '+'
    
    answer = 0
    for i in xrange(1, len(stack)):
        if stack[i-1:i+1] in ['+-', '-+']:
            answer += 1
    
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer

IN.close()
OUT.close()
