infile = open('harmony.in')
outfile = open('harmony.out', 'w')

T = int(infile.readline().strip())

def gcd(a, b):
    if a > b:
        return gcd(b, a)
    if a == 0:
        return b
    return gcd(b % a, a)

def lcm(a, b):
    return a * b / gcd(a, b)

def lowest_factor_in_range(n, lower, upper):
    print n, lower, upper
    if lower * lower < n:
        f = lower
        while f <= upper and f * f <= n:
            if n % f == 0:
                return f
            f += 1
        return lowest_factor_in_range(n, n / lower + 1, upper)
    else:
        f = n / lower
        while f > 0 and n / f <= upper:
            if n % f == 0:
                return n / f
            f -= 1
    return None

def get_best_pitch():

    # test for very low pitch
    print 'checking low pitch'

    answer = lowest_factor_in_range(gcd_list[0], L, H)
    if answer is not None:
        return answer


    # test breakpoints
    for ix in breakpoints:
        print 'working on breakpt', ix
        if ix == N - 1: continue
        lower = lcm_list[ix]
        upper = gcd_list[ix + 1]
        
        answer = lowest_factor_in_range(upper/lower, (L - 1)/lower + 1, H/lower)
        if answer is not None:
            return lower * answer


    print 'checking high pitch'

    # test for very high pitch
    answer = L - ((L - 1) % lcm_list[-1]) + lcm_list[-1] - 1
    if answer <= H:
        return answer
    return None



for t in xrange(T):
    print 'working on case', t + 1

    N, L, H = [int(s) for s in infile.readline().strip().split()]

#    print N, L, H

    
    freqs = [int(s) for s in infile.readline().strip().split()]
    freqs = sorted(freqs)

    gcd_list = [1] * N
    gcd_list[N - 1] = freqs[N - 1]
    for i in xrange(N - 2, -1, -1):
        gcd_list[i] = gcd(freqs[i], gcd_list[i + 1])

    lcm_list = [1] * N
    lcm_list[0] = freqs[0]
    for i in xrange(1, N):
        lcm_list[i] = lcm(freqs[i], lcm_list[i - 1])


#    print freqs
#    print gcd_list
#    print lcm_list

    lowest_possible = 0 # includes the low end

    breakpoints = []
    
    for i in xrange(N):
        for j in xrange(N - 1, lowest_possible, -1):
            if freqs[j] % freqs[i] != 0:
                lowest_possible = j
                break
        if i >= lowest_possible:
            breakpoints.append(lowest_possible)
            lowest_possible += 1

    print 'got breakpoints'

    answer = get_best_pitch()

    if answer is None:
        outfile.write('Case #%d: NO\n' % (t + 1))
    else:
        outfile.write('Case #%d: %d\n' % (t + 1, answer))
