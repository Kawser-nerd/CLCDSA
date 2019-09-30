from sys import stdin

def each_case(J, P, S, K):
    if S <= K:
        for i in xrange(J):
            for j in xrange(P):
                for k in xrange(S):
                    print str(1+i) + ' ' + str(1+j) + ' '  + str(1+k)
    else:
        for i in xrange(J):
            for j in xrange(P):
                for k in xrange(K):
                    print str(1+i) + ' ' + str(1+j) + ' '  + str(1+((i+j+k)%S))

T = int(stdin.readline())
for t in xrange(1,T+1):
    J, P, S, K = map(int, stdin.readline().split())
    print 'Case #{}: {}'.format(t, J*P*min(S, K))
    each_case(J, P, S, K)
