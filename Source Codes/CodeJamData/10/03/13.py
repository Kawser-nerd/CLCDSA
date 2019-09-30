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


if __name__ == "__main__":
    f = open(sys.argv[1]) # open file

    [N] = getints(f)
    for cases in xrange(0,N): # loop over cases
        ans = 0
        # main
        
        R, k, G = getints(f)
        g = getints(f)

        fs = []
        b = [0] * G
        i = 0
        j = 0
        while not b[i]:
            b[i] = j

            empty = k
            lol = i
            while empty > 0 and g[i] <= empty:
                empty -= g[i]
                i = (i + 1) % G
                if i == lol: break
            j += 1
            fs.append(k - empty)


        i = b[i]

        Js = fs[i:]
        J, j = sum(Js), len(Js)

        if R < len(fs): ans = sum(fs[:R])
        else:
            R -= len(fs)
            a, b = divmod(R, j)
            ans = sum(fs) + a * J + sum(Js[:b])


        # main
        print "Case #%d: %d"%( cases+1, ans ) # answer output
