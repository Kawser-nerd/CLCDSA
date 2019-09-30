#! /usr/bin/env python
import sys, re
# some reading functions
getline = lambda f: f.readline().strip()
gettoken = lambda f: re.split("\s+", getline(f))
getint = lambda f: int(getline(f))
getints = lambda f: map(int, gettoken(f))

# number theory / combinatorics
product = lambda l: reduce(lambda x,y: x*y, l) if l else 1
factorial = lambda n: product(xrange(n, 1, -1))
nPr = lambda n, r: product(xrange(n,n-r,-1))
nCr = lambda n, r: nPr(n, r) / factorial(r)
nMr = lambda l: factorial(sum(l)) / product(map(factorial,l))
gcd = lambda x,y: gcd(y, x%y) if y != 0 else x
lcm = lambda x,y: x * y / gcd(x, y)
def gcd2(a, b):
    if b == 0: return (a, 1, 0)
    (d,x,y) = gcd2(b, a % b)
    return (d, y, x - a / b * y)

f = open(sys.argv[1]) # open file

def baseN(num,b):
  return ((num == 0) and  "0" ) or ( baseN(num // b, b).lstrip("0") + "0123456789abcdefghijklmnopqrstuvwxyz"[num % b])


def tobase(n, b=2):
    if n == 0: return result
    k = n
    result = 0
    base = 1
    while k != 0:
        result += (k % 10) * base
        k /= 10
        base *= b
    return result

dp = map(lambda x:{}, [0]*11)

def happy(n, b):
    global iter
    global dp

    k = n
    l = [k]

    for c in xrange(10000000):
        r = 0
        while k != 0:
            d = k % b
            r += d*d
            k /= b
        if r == 1 or (r in dp[b] and dp[b][r] == 1):
            l.append(r)
            for h in l:
                dp[b][h] = 1
            return True
        else:
            if r == 0 or r in l or (r in dp[b] and not dp[b][r]):
                l.append(r)
                for h in l:
                    dp[b][h] = 0
                return False
            l.append(r)
        k = r
    return False

[N] = getints(f)
for cases in xrange(0,N): # loop over cases
    ans = 0
    # main

    bases = getints(f)
    
    for i in xrange(2,100000):
        ahh = all(map(lambda b: happy(i, b), bases))
        if ahh:
            ans = i
            break
    
    # main
    print "Case #%d: %d"%( cases+1, ans ) # answer output
