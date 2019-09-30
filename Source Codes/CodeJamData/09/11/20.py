import psyco
psyco.full()

def happy(k, b, memo):
    if (k, b) in memo:
        return memo[(k, b)]

    if b == 2 or b == 4:
        return True

    seen = [k]
    m = k
    while True:
        sqs = 0
        while m > 0:
            sqs += (m % b) ** 2
            m = m // b
        m = sqs
        if (m, b) in memo:
            res = memo[(m, b)]
            break

        if m in seen:
            res = False
            break
        else:
            seen += [m]

    memo[(k, b)] = res
    return res

def solve():
    memo = {}
    for b in xrange(2,11):
        memo[(1, b)] = True

    for case in xrange(input()):
        bases = [int(s) for s in raw_input().split()]

        i = 2
        while True:
            if all(happy(i, b, memo) for b in bases[::-1]):
                break
            i += 1

        res = i

        print 'Case #%d: %d' % (case+1, res)

solve() # so that psyco can do its magic
