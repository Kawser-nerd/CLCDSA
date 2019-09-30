import sys

t = int(sys.stdin.readline().strip())

for i in range(t):
    smax, ss = sys.stdin.readline().strip().split()
    smax = int(smax)
    s = []
    for j in range(smax + 1):
        s.append(int(ss[j]))
    sum = 0
    max = 0
    for j in range(smax + 1):
        if ((j > sum) and (j - sum > max)):
            max = j - sum
        sum += s[j]
    print "Case #%d: %d" % (i + 1, max)
