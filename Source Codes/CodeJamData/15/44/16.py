
from collections import defaultdict as ddic
PP = 1000000007

def solve(R,C):
    dp21 = [0 for i in xrange(R+1)]
    dp23 = [0 for i in xrange(R+1)]
    dp24 = [0 for i in xrange(R+1)]
    dp26 = [0 for i in xrange(R+1)]
    dp212 = [0 for i in xrange(R+1)]
    
    dp31 = [0 for i in xrange(R+1)]
    dp33 = [0 for i in xrange(R+1)]
    dp34 = [0 for i in xrange(R+1)]
    dp36 = [0 for i in xrange(R+1)]
    dp312 = [0 for i in xrange(R+1)]
    
    #ith entry is number of distinct ways of tiling
    # up to i rows ending with a row that contains...
    #  dp2 : last row not full of 3s
    #  dp3 : last row full of 3s
    dp21[0] = 1
    dp31[0] = 1

    for row in xrange(R+1):
        if row+2 <= R:
            dp31[row+2] += dp21[row]
            dp31[row+2] %= PP
            dp33[row+2] += dp23[row]
            dp33[row+2] %= PP
            dp34[row+2] += dp24[row]
            dp34[row+2] %= PP
            dp36[row+2] += dp26[row]
            dp36[row+2] %= PP
            dp312[row+2] += dp212[row]
            dp312[row+2] %= PP
        if row+1 <= R:
            dp21[row+1] += dp31[row]
            dp21[row+1] %= PP
            dp23[row+1] += dp33[row]
            dp23[row+1] %= PP
            dp24[row+1] += dp34[row]
            dp24[row+1] %= PP
            dp26[row+1] += dp36[row]
            dp26[row+1] %= PP
            dp212[row+1] += dp312[row]
            dp212[row+1] %= PP
            
        if C%3==0:
            if row+2 <= R:
                dp23[row+2] += 3*dp31[row]
                dp23[row+2] %= PP
                dp23[row+2] += 3*dp33[row]
                dp23[row+2] %= PP
                dp212[row+2] += 3*dp34[row]
                dp212[row+2] %= PP
                dp26[row+2] += 3*dp36[row]
                dp26[row+2] %= PP
                dp212[row+2] += 3*dp312[row]
                dp212[row+2] %= PP
        if C%4==0:
            if row+3 <= R:
                dp24[row+3] += 4*dp31[row]
                dp24[row+3] %= PP
                dp212[row+3] += 4*dp33[row]
                dp212[row+3] %= PP
                dp24[row+3] += 4*dp34[row]
                dp24[row+3] %= PP
                dp212[row+3] += 4*dp36[row]
                dp212[row+3] %= PP
                dp212[row+3] += 4*dp312[row]
                dp212[row+3] %= PP
        if C%6==0:
            if row+2 <= R:
                dp26[row+2] += 6*dp31[row]
                dp26[row+2] %= PP
                dp26[row+2] += 6*dp33[row]
                dp26[row+2] %= PP
                dp212[row+2] += 6*dp34[row]
                dp212[row+2] %= PP
                dp26[row+2] += 6*dp36[row]
                dp26[row+2] %= PP
                dp212[row+2] += 6*dp312[row]
                dp212[row+2] %= PP
    return (dp21[R]+dp23[R]/3+dp24[R]/4+dp26[R]/6+dp212[R]/12+dp31[R]+dp33[R]/3+dp34[R]/4+dp36[R]/6+dp312[R]/12)%PP 
"""
def solve(R,C):
    dp2 = [0 for i in xrange(R+1)]
    dp3 = [0 for i in xrange(R+1)]
    #ith entry is number of distinct ways of tiling
    # up to i rows ending with a row that contains...
    #  dp2 : last row not full of 3s
    #  dp3 : last row full of 3s
    dp2[0] = 1
    dp3[0] = 1

    for row in xrange(R+1):
        if row+2 <= R:
            dp3[row+2] += dp2[row]
            dp3[row+2] %= PP
        if row+1 <= R:
            dp2[row+1] += dp3[row]
            dp2[row+1] %= PP
        if C%3==0:
            if row+2 <= R:
                dp2[row+2] += 3*dp3[row]
                dp2[row+2] %= PP
        if C%4==0:
            if row+3 <= R:
                dp2[row+3] += 4*dp3[row]
                dp2[row+3] %= PP
        if C%6==0:
            if row+2 <= R:
                dp2[row+2] += 6*dp3[row]
                dp2[row+2] %= PP
    return (dp2[R]+dp3[R])%PP
"""

########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    rrF = lambda: map(float,rr().split())
    for tc in xrange(rrI()):
        R,C = rrM()
        zetaans = solve(R,C)

        zeta = "Case #%i: "%(tc+1) + str(zetaans)

        print zeta
        fo.write(zeta+'\n')
fo.close()
