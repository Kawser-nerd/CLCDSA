def pos(n, pd, pg):
    pdf = Fraction(pd, 100)
    if pdf.denominator <= n:
        if pdf.numerator > 0 and pg == 0:
            return False
        if pdf.numerator != pdf.denominator and pg == 100:
            return False
        return True
    return False
from fractions import Fraction
for c in xrange(input()):
    n, pd, pg = map(int, raw_input().split())
    if pos(n, pd, pg):
        print "Case #%d: Possible" % (c+1)
    else:
        print "Case #%d: Broken" % (c+1)