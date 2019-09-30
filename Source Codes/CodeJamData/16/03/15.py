from sympy import *
import random
n = 32
j = 500

arr = []

f = open("out.txt", "w")

def findDivisor(x):
    res = 2
    while x % res != 0 and res < 100:
        res += 1
    return res

for i in xrange(2 ** (n - 2)):
    t = bin(i)[2:]
    t = "0" * (n - 2 - len(t)) + t
    t = "1" + t + "1"
    # print "T " + t
    ok = True
    for base in xrange(2, 11):
        if isprime(int(t, base)) or findDivisor(int(t, base)) == 100:
            ok = False
            break
    if ok:
        data = []
        data.append(t)
        for base in xrange(2, 11):
            num = int(t, base)
            data.append(str(findDivisor(num)))

        arr.append(data)

        if len(arr) == j:
            break

print >>f, "Case #1:"

for l in arr:
    print >>f, ' '.join(l)


