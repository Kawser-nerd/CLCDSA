import fileinput
import math

fitr = iter (fileinput.input())

for case in range (int(fitr.next())):
    size = int(fitr.next())
    a = [int(x) for x in fitr.next().split()]
    b = [int(x) for x in fitr.next().split()]

    a.sort()
    b.sort()
    b.reverse()
    c = 0

    for i in range(0, size):
        c += a[i] * b[i]

    print 'Case #%d: %d' % (case + 1, c)
    
