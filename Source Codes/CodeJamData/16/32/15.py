from sys import stdin
from string import zfill

def each_case(B, M):
    if M < 2**(B-2):
        print zfill(bin(M)[2:], B-1) + '0'
        for i in xrange(B-1):
            print '0'*(i+2) + '1'*(B-i-2)
    elif M == 2**(B-2):
        print '0' + '1'*(B-1)
        for i in xrange(B-1):
            print '0'*(i+2) + '1'*(B-i-2)

T = int(stdin.readline())
for t in xrange(1,T+1):
    B, M = map(int, stdin.readline().split())
    print 'Case #{}: {}'.format(t, 'POSSIBLE' if (M <= 2**(B-2)) else 'IMPOSSIBLE')
    each_case(B, M)
