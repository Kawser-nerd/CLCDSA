#!/usr/bin/python

import sys

primes = [
      2,      3,      5,      7,     11,     13,     17,     19,     23,     29 ,
     31,     37,     41,     43,     47,     53,     59,     61,     67,     71 ,
     73,     79,     83,     89,     97,    101,    103,    107,    109,    113 ,
    127,    131,    137,    139,    149,    151,    157,    163,    167,    173 ,
    179,    181,    191,    193,    197,    199,    211,    223,    227,    229 ,
    233,    239,    241,    251,    257,    263,    269,    271,    277,    281 ,
    283,    293,    307,    311,    313,    317,    331,    337,    347,    349 ,
    353,    359,    367,    373,    379,    383,    389,    397,    401,    409 ,
    419,    421,    431,    433,    439,    443,    449,    457,    461,    463 ,
    467,    479,    487,    491,    499,    503,    509,    521,    523,    541 ,
    547,    557,    563,    569,    571,    577,    587,    593,    599,    601 ,
    607,    613,    617,    619,    631,    641,    643,    647,    653,    659 ,
    661,    673,    677,    683,    691,    701,    709,    719,    727,    733 ,
    739,    743,    751,    757,    761,    769,    773,    787,    797,    809 ,
    811,    821,    823,    827,    829,    839,    853,    857,    859,    863 ,
    877,    881,    883,    887,    907,    911,    919,    929,    937,    941 ,
    947,    953,    967,    971,    977,    983,    991,    997,   1009]

def readdata():
    def rl():
        return sys.stdin.readline().strip().split(' ')
    n = int(rl()[0])
    cases = []
    for i in range(n):
        A, B, P = (int(x) for x in rl())
        case = (A,B,P)
        cases.append(case)
    return cases

def facs(x,mustbe):
    i = 0
    r = []
    while primes[i] <= x and i < len(primes)-1:
        if x % primes[i] == 0 and primes[i] >= mustbe:
            r.append(primes[i])
        i+=1
    return set(r)

case_number = 1
for case in readdata():
    numbers = xrange(case[0],case[1]+1)
    nfacs = [[x,facs(x,case[2])] for x in numbers]
    r = len(nfacs)
    while len(nfacs) > 0:
        n = nfacs.pop(0)
        mf = n[1]
        restart = True
        while restart:
            restart = False
            for on in nfacs:
                #print n[0],mf,on
                if len(mf & on[1]) > 0:
                    nfacs.remove(on)
                    mf = mf | on[1]
                    restart = True
                    r -= 1
                    break
        #print n[0],mf
    print 'Case #' + str(case_number) + ':',r
    case_number += 1
