import sys
import math

def opt(K, pancakes):
    ret = pow(pancakes[-1][0], 2) + 2 * pancakes[-1][0] * pancakes[-1][1]
    pancakes = pancakes[:-1]
    pancakes.sort(key=lambda x : -2 * x[0] * x[1])
    ret += sum([2 * x[0] * x[1] for x in pancakes[:K-1]])
    return ret

def solve(i):
    [N, K] = map(int, sys.stdin.readline().split())
    pancakes = [map(int, sys.stdin.readline().split()) for i in xrange(N)]
    pancakes.sort(key=lambda x: x[0])
    ret = 0
    #print pancakes
    for i in xrange(K, N+1):
        ret = max(ret, opt(K, pancakes[:i]))
        #print i, K, pancakes[:i], opt(K, pancakes[:i]), ret
    print "%.9f" % (ret * math.pi)

if __name__ == '__main__':
	c = int(sys.stdin.readline())
	for i in range(c):
		sys.stdout.write('Case #%d: ' % (i+1,))
		solve(i)
