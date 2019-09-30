import sys
from collections import defaultdict

alpha = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
assert len(alpha) == 26

def run(S):
    lcounts = defaultdict(int)
    ncounts = [0]*10
    for l in S:
        lcounts[l] += 1

    def setk(k, kstr, l):
        xxx = lcounts[l]
        ncounts[k] = xxx
        for lete in kstr:
            lcounts[lete] -= xxx

    setk(0, 'ZERO', 'Z')
    setk(2, 'TWO', 'W')
    setk(6, 'SIX', 'X')
    setk(8, 'EIGHT', 'G')
    setk(7, 'SEVEN', 'S')
    setk(5, 'FIVE', 'V')
    setk(9, 'NINE', 'I')
    setk(1, 'ONE', 'N')
    setk(4, 'FOUR', 'U')
    setk(3, 'THREE', 'R')

    assert not sum(lcounts.values())
    return ''.join(a*b for a,b in zip(list('0123456789'), ncounts))


f = file(sys.argv[1],'r')
T = int(f.readline().strip())
for case in range(1,T+1):
    S = f.readline().strip()
    ans = run(S)
    print 'Case #%d: %s' % (case, ans)


    # twos = lcounts['W']
    # ncounts[2] = twos
    # lcounts['T'] -= twos
    # lcounts['W'] -= twos
    # lcounts['O'] -= twos

    # sixes = lcounts['X']
    # ncounts[6] = sixes
    # lcounts['S'] -= sixes
    # lcounts['I'] -= sixes
    # lcounts['X'] -= sixes

    # zeros = lcounts['Z']
    # ncounts[0] = zeros
    # lcounts['Z'] -= zeros
    # lcounts['E'] -= zeros
    # lcounts['R'] -= zeros
    # lcounts['O'] -= zeros
