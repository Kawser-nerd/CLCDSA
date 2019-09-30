import sys
import fractions

infile = sys.stdin

def genprimes():
    composites = {}  
    candidate = 2
    while True:
        if candidate not in composites:
            yield candidate        
            composites[candidate*candidate] = [candidate]
        else:
            for p in composites[candidate]:
                composites.setdefault(p + candidate, []).append(p)
            del composites[candidate]
        candidate += 1


powers = set()
pmax = 1e12
for p in genprimes():
    power = p*p
    if power>pmax: break
    while power<pmax:
        powers.add(power)
        power *= p
    


def get_spread(N):
    if N==1: return 0
    # 1 plus number<=N
    return 1 + sum(1 for p in powers if N>=p)
        

T = int(infile.readline())
for i in xrange(T):
    N = int(infile.readline())
    print("Case #%d: %d" % (i+1, get_spread(N)))
