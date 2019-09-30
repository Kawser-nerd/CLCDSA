import sys, fractions
rl = lambda: sys.stdin.readline().strip()

t = int(rl())
for cc in range(t):
    print "Case #%d:" % (cc+1),
    n, p_day, p_all = map(int, rl().split())


    g = 100 / fractions.gcd(p_day, 100)
    if (n >= g and not (p_day < 100 and p_all == 100) 
            and not (p_day > 0 and p_all == 0)):
        print "Possible"
    else:
        print "Broken"


