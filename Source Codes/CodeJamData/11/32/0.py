infile = open('space_emergency.in')
outfile = open('space_emergency.out', 'w')

T = int(infile.readline().strip())

for trial in xrange(T):
    l = [int(s) for s in infile.readline().strip().split()]
    L, t, N, C = l[:4]
    a = l[4:]

    distances = a * (N / C + 1)
    distances = distances[:N]

    print 'working on case', trial + 1
#    print distances

    cost = sum(distances) * 2

    start_ix = 0

    while start_ix < N and t >= distances[start_ix] * 2:
        t -= distances[start_ix] * 2
        start_ix += 1

    if start_ix == N:
        outfile.write('Case #%d: %d\n' % (trial + 1, cost))
        continue

    savings = [d for d in distances[start_ix:]]
    savings[0] -= t / 2
    savings = sorted(savings)[::-1]
    total_savings = sum(savings[:min(L, N - start_ix)])

    outfile.write('Case #%d: %d\n' % (trial + 1, cost - total_savings))
    
