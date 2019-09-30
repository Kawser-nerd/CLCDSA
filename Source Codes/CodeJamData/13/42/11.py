def get_worst(n, x):
    rank = 0
    for i in xrange(n):
        if x == 0:
            break
        rank += pow(2, n - i - 1)
        x -= 1
        x /= 2
    return rank

def get_best(n, x):
    return pow(2, n) - 1 - get_worst(n, pow(2, n) - 1 - x)

def solve_must(n, p):
    low, high = 0, pow(2, n)
    while high - low > 1:
        middle = low + high >> 1
        if get_worst(n, middle) < p:
            low = middle
        else:
            high = middle
    return low

def solve_may(n, p):
    low, high = 0, pow(2, n)
    while high - low > 1:
        middle = low + high >> 1
        if get_best(n, middle) < p:
            low = middle
        else:
            high = middle
    return low

for t in xrange(input()):
    n, p = map(int, raw_input().split())
    print "Case #%d: %d %d" %(t + 1, solve_must(n, p), solve_may(n, p))
