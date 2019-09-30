from decimal import Decimal, getcontext
getcontext().prec = 60
f = open('C.txt')
C = int(f.readline())
for c in range(C):
    n = int(f.readline())
    a = Decimal(3)
    b = Decimal(5)
    a = ((a + b.sqrt())**n)%1000
    print "Case #%d: %03d" % (c+1, int(a))
