def gcd(a, b):
    if a == 0 or b == 0:
        return a + b
    elif a > b:
        return gcd(b, a % b)
    else:
        return gcd(a, b % a)

if __name__ == '__main__':
    T = int(raw_input())
    for caseno in xrange(T):
        nums = [int(s) for s in raw_input().split()]
        N = nums[0]
        xs = nums[1:]
        xs.sort()
        diffs = [xs[i + 1] - xs[i] for i in xrange(len(xs) - 1) if xs[i + 1] != xs[i]]
        if diffs:
            g = diffs[0]
            for d in diffs[1:]:
                g = gcd(g, d)
            res = (g - (xs[0] % g)) % g
        else:
            res = 0
        print 'Case #%d: %d' % (caseno + 1, res)
