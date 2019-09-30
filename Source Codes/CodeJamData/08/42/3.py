import sys
import math

def do_test(input):
    line = input.readline().split(' ')
    N = int(line[0])
    M = int(line[1])
    A = int(line[2])

    flipped = False
    if M>N:
        z = M
        M = N
        N = z
        flipped = True
    if A>M*N:
        return "IMPOSSIBLE"
    beta = -((-A)%M)
    alpha = (A-beta)//M + beta
    a = M
    b = M-1
    x2 = 0
    x1 = alpha-beta
    x3 = -beta
    y3 = 0
    y1 = b
    y2 = a

    if not flipped:
        return str(x1)+' '+str(y1)+' '+str(x2)+' '+str(y2)+' '+str(x3)+' '+str(y3)
    else:
        return str(y1)+' '+str(x1)+' '+str(y2)+' '+str(x2)+' '+str(y3)+' '+str(x3)

input = sys.stdin

N = int(input.readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%(case)d: %(answer)s' % \
        {'case': test+1, 'answer': answer}
    sys.stdout.flush()
