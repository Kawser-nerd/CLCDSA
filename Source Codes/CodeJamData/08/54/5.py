import sys
import math

MOD = 10007

def gcd(a, b):
    if b==0:
        return [1,0]
    k = a//b
    r = a-b*k
    g = gcd(b, r)
    return [g[1], g[0]-g[1]*k]

def inv(x):
    g = gcd(MOD, x)
    return g[1]%MOD


def pre_fact():
    f = 1
    res = [1]
    for n in range(1, MOD):
        f = (f*n)%MOD
        res.append(f)
    return res

fact = pre_fact()

def fact_mod(x):
    global fact
    if x==0:
        return 1
    r = x%MOD
    k = x//MOD
    kk = 1
    if k%2==1:
        kk = -1
    return (fact[r]*fact_mod(k)*kk)%MOD

def fact_ord(x):
    r = x%MOD
    k = x//MOD
    if k==0:
        return 0
    return k+fact_ord(k)

def binom(k, n):
    if fact_ord(n)>fact_ord(k)+fact_ord(n-k):
        return 0
    return (fact_mod(n)*inv((fact_mod(k)*fact_mod(n-k))%MOD))%MOD

def ev(a, b):
    dx = b[0]-a[0]
    dy = b[1]-a[1]
    if dx<0 or dy<0:
        return 0
    s = dx+dy
    if s%3 != 0:
        return 0
    s /= 3
    dx -= s
    dy -= s
    if dx<0 or dy<0:
        return 0
    n = dx + dy
    k = dx
    return binom(k, n)

def do_test(input):
    line = input.readline().split(' ')
    H = int(line[0])
    W = int(line[1])
    R = int(line[2])
    rocks = []
    for i in range(R):
        line = input.readline().split(' ')
        rocks.append([int(line[0]), int(line[1])])
    for j in range(R):
        for k in range(R-1):
            if rocks[k][0]+rocks[k][1]>rocks[k+1][0]+rocks[k+1][1]:
                z = rocks[k]
                rocks[k] = rocks[k+1]
                rocks[k+1] = z
    s = 0
    for x in range(1<<R):
        lastR = [1,1]
        prod = -1
        for b in range(R):
            if x&(1<<b):
                prod = (-prod*ev(lastR, rocks[b])) % MOD
                lastR = rocks[b]
        prod = (-prod*ev(lastR, [H, W])) % MOD
        s = (s + prod) % MOD

    return str(s)

input = sys.stdin

N = int(input.readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%(case)d: %(answer)s' % \
        {'case': test+1, 'answer': answer}
    sys.stdout.flush()
