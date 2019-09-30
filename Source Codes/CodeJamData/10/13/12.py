import math

def memoize(function):
    cache = {}
    def decorated_function(*args):
        if args in cache:
            return cache[args]
        else:
            val = function(*args)
            cache[args] = val
            return val
    return decorated_function


def solve():
    S = [int(x) for x in input.readline().split(' ')]
    return S

@memoize
def fib(n):
    if n < 2: return 1
    else: return fib(n-1) + fib(n-2)
    
p = fib(31)
q = fib(30)
# phi = p/q

def s(n):
    return math.ceil(n * q / p + 1)
def t(n):
    return math.ceil(n * p / q)

input = open('3.in', 'r')
output = open('3.out', 'w')
n = int(input.readline())

def solve():
    (A1,A2,B1,B2) = [int(x) for x in input.readline().split(' ')]
    if (A2-A1 > B2-B1):
        (B1,B2,A1,A2) = (A1,A2,B1,B2)
    count = 0
    for a in range(A1,A2+1):
        x = (min(t(a),B2)) - max(s(a),B1) + 1
        if x < 0: x = 0
        count += B2 - B1 + 1 - x
    return count

for i in range(1,n+1):
    result = solve()
    print "Case #%d: %d" % (i, result)
    output.write("Case #%d: %d\n" % (i, result))
