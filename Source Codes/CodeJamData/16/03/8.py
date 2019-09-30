import itertools

# precompute some primes
primes = [2, 3]
numPrime = 2
for n in xrange(5, 10 ** 6):
    if n % 10000 == 0: print n
    for i in xrange(numPrime):
        if n % primes[i] == 0:
            break
        if n < primes[i] ** 2:
            break
    if n % primes[i] == 0:
        continue
    primes.append(n)
    numPrime += 1
    
def genPrime():
    for i in xrange(numPrime):
        yield primes[i]
    #todo
    
def factor(n):
    for p in genPrime():
        if n % p == 0:
            return p
        if n < p*p:
            break
    return n

def toBase(s, base):
    r = 0
    for c in s:
        r *= base
        r += ord(c) - ord('0')
    return r
    
N = 32
J = 500

OUT = open('output.txt', 'w')
OUT.write('Case #1:\n')
for l in itertools.product(['0', '1'], repeat = N-2):
    s = '1' + ''.join(l) + '1'
    jamCoin = True
    factors = []
    
    for base in xrange(2, 11):
        x = toBase(s, base)
        factors.append(factor(x))
        if factors[-1] == x: # may have false negative, but we don't need to be tight
            jamCoin = False
            break
    
    if jamCoin:
        answer = s + ' ' + ' '.join(map(str,factors))
        OUT.write(answer + '\n')
        print answer
        J -= 1
        if J == 0: break

OUT.close()