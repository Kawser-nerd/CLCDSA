import sys

if sys.argv[1:]:
    sys.stdin = open(sys.argv[1] + '.in')
    sys.stdout = open(sys.argv[1] + '.out', 'w')

def solve():
    n, k = map(int, sys.stdin.readline().split())
    if (k + 1) % (1 << n) == 0:
        return 'ON'
    else:
        return 'OFF'

ccc = int(sys.stdin.readline())
for cc in range(1, ccc + 1):
    print "Case #%d: %s" % (cc, solve())
