import sys
import math

countprimes = [0]*1000001

primes = []
np = 0
for x in range(2, 1000001):
    is_prime = True
    for p in primes:
        if p*p>x:
            break
        if x%p==0:
            is_prime = False
            break
    if is_prime:
        primes.append(x)
        np += 1
    countprimes[x] = np


def solve(n):
    if n==1:
        return 0
    res = 1
    for power in range(2, 41):
        pmax = int(math.ceil(math.exp(math.log(n)/power))+10)
        while pmax**power>n:
            pmax -= 1
        res += countprimes[pmax]
    return res    
        

def readline():
    return input.readline().strip(' \r\n\t')

def do_test(input):
    n = int(readline())
    res = solve(n)
    return str(res)

input = sys.stdin

N = int(readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%d: %s' % (test+1, answer)
    sys.stdout.flush()
    
