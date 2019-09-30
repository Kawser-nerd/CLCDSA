from decimal import *

i = open('1c0.in', 'r')

test_cases = int(i.readline())

getcontext().prec = 100
d = Decimal('3.0') + Decimal('5.0').sqrt()

for t in range(1, test_cases+1):
    n = int(i.readline())
    v = 1

    for p in range(n):
        v *= d

    print "Case #%d: %03d" % (t, int((v.to_integral(ROUND_FLOOR) % 1000).to_eng_string()) )
