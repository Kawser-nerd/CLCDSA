from math import *

def sieve(n):
    s = [True]*n
    for i in range(3, int(n**0.5)+1, 2):
        if s[i]:
            s[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if s[i]]


with open('input.in', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        primes = sieve(1000000)
        for casenum in range(1, numcases+1):
            print(casenum)
            numpeople = int(fin.readline())
            spread = 0
            
            if numpeople > 1:
                spread = 1
            for i in range(len(primes)):
                if (primes[i]*primes[i] > numpeople):
                    break
                mult = primes[i]*primes[i]
                while (mult <= numpeople):
                    spread += 1
                    mult *= primes[i]
                i += 1

            solnstr = str(spread)













            fout.write("Case #"+str(casenum)+": "+solnstr+'\n')
