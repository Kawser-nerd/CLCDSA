import math

def pieces(layer):
    # is the 2(layer) + 1 triangular number
    return sum(range(1, 2 * layer + 2))

def binom(a, k):
    return math.exp(math.lgamma(a+1) - (math.lgamma(k+1) + math.lgamma(a - k + 1)))

def solve(n, x, y):
    layer = (abs(x) + y) // 2
    if x == 0:
        # center
        # only filled iff the whole triangle for that layer is filled
        return 1.0 if n >= pieces(layer) else 0.0
    else:
        # for off-center, we need the previous layer filled,
        # as well as at least (y+1) to land on the correct side
        leftover = n - pieces(layer - 1)
        if leftover <= 0:
            return 0.0
        height = 2 * layer
        if leftover - height >= y + 1:
            return 1.0

        p = 0.0
        for left in range(y + 1, leftover + 1):
            # valid options
            right = leftover - left
            p += binom(leftover, left) * (2**-leftover)
        return p
    return 'UNK'

with open('B-large.in', 'r') as file:
    T = int(file.readline())
    for case in range(1, T+1):
        (n, x, y) = map(int, file.readline().split())
        print 'Case #{}: {}'.format(case, solve(n, x, y))
