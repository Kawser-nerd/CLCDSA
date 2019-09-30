import sys
from fractions import Fraction
from fractions import gcd
from collections import defaultdict
import copy
import multiprocessing
cin = sys.stdin.readline

def nrt(n):
    op = n
    res = 0
    one = 1
    while one * 4 <= op:
        one *= 4
    while one != 0:
        #print op, res+one
        if op >= res + one:
            op -= res + one
            res = (res >> 1) + one
        else:
            res >>= 1
        one >>= 2
    #print res, op
    return op

def solve(s):
    out = 0
    unknown = 0
    S = len(s)
    bits = list()
    #print S
    for e, i in enumerate(s):
        out *= 2
        unknown *= 2
        if i == '1':
            out += 1
        elif i == '?':
            unknown += 1
            #out += 1
            bits.append((1 << (S-e-1)))
                

    answer = (out | unknown)
    #print bin(answer)
    #print bits
    x = nrt(answer)
    #print bin(answer), x
    while x != 0:
        #print answer, x
        answer -= x
        #print answer
        #round down
        new_answer = out
        for num in bits:
            if (new_answer | num) <= answer:
                new_answer |= num
        answer = new_answer
        #print answer
        x = nrt(answer)
        

    return bin(answer)[2:]
    

 
            
      
    
                

def procfunc(tup):
    x = solve(*tup[1:])
    print >>sys.stderr, "SOLVE", tup[0]
    return x


if __name__ == '__main__':
    T = int(cin())
    inputs = []
    for cnum in xrange(T):
        arr = cin().strip()
        inputs.append((cnum, arr))

    if False:  #need subprocess??
        pool = multiprocessing.Pool()
        output = pool.map_async(procfunc, inputs, 1).get(999999)
    else:
        output = list(procfunc(x) for x in inputs)

    for i, out in enumerate(output):
        #output processing goes here
        #print >>sys.stderr, cnum
        print "Case #%d: %s" % (i+1, out)

                    
            
        
    
