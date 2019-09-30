file = 'A-large'
from fractions import gcd
def mcd(a, b):
    return a * b / gcd(a,b)
    
fin = open(file + '.in', 'r')
fout = open(file + '.out', 'w')

def algorithm(N, Pd, Pg):
    print N, Pd, Pg
    if Pd == 0:
        if Pg != 100: return 'Possible'
        else: return 'Broken'
    
    d1 = 100 / gcd(100, Pd)
    print d1
    if N >= d1 and (Pg != 100 or Pg == Pd == 100) and Pg != 0: return 'Possible'
    else: return 'Broken'


def process():
    N, Pd, Pg = ( int(x) for x in fin.readline().rstrip().split(' ') )
    return algorithm(N, Pd, Pg)

num_cases = int(fin.readline().rstrip())

for i in range(1, num_cases + 1):
    result = process()
    fout.write('Case #%d: %s\n' % (i, result))

fin.close()
fout.close()