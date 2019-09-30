inf = 'A-large.in'
#inf = 'in.txt'
f_in = open(inf)
f_out = open('out.txt', 'w')

def slove(case):
    if case % 10 == 0:
        print case
    n = int(f_in.next())
    wires = []
    for i in xrange(n):
        l = f_in.next().split(' ')
        wires += [[int(s) for s in l],]
    wires.sort(lambda a,b : a[0] - b[0])
    ans = 0
    l = len(wires)
    for i in xrange(l):
        w1 = wires[i]
        for j in xrange(i + 1, l):
            w2 = wires[j]
            if w2[1] < w1[1]:
                ans += 1
    print >>f_out, 'Case #' + str(case)+": " + str(ans)

T = int(f_in.next())


for case in xrange(1, T + 1):
    slove(case)

f_out.close()