import math
inf = 'B-large.in'
#inf = 'in.txt'
f_in = open(inf)
f_out = open('out.txt', 'w')

def find_parts(l, p, c):
    parts = 1
    t = l * c
    while t < p:
        parts += 1
        t *= c
    return parts

def slove(case):
    ln = f_in.next().split(' ')
    l, p, c = int(ln[0]), int(ln[1]), int(ln[2])
    ans = int(math.ceil(math.log(find_parts(l, p, c), 2)))
    print >>f_out, 'Case #' + str(case) + ": " + str(ans)

T = int(f_in.next())
for case in xrange(1, T + 1):
    slove(case)
f_out.close()
f_in.close()