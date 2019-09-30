import numpy

M = numpy.matrix([[6,2],[-2,0]])
V = numpy.matrix([[-3], [2]])

def pow(M, e, d):
    i = 1
    accum = numpy.matrix([[1,0],[0,1]])
    working = M
    while True:
        if e & i:
            accum = (accum * working) % d
        working = (working * working) % d
        i = i * 2
        if e < i:
            break
    return accum

if __name__ == '__main__':
    t = raw_input()
    for i in range(int(t)):
        n = int(raw_input())
        v = (pow(M, n, 1000) * V).A[1][0] - 1
        v = (v+1000)%1000
        print 'Case #%d: %03d' % (i+1, v)
