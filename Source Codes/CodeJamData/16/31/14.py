from sys import stdin

def each_case(N, P):
    max, max2, argmax, argmax2 = -1, P[0], 0, 0
    for i, p in enumerate(P):
        if max < p:
            max2 = max
            max = p
            argmax2 = argmax
            argmax = i
        elif max2 < p:
            max2 = p
            argmax2 = i

    max_party, max2_party = chr(argmax+65), chr(argmax2+65)
    plan = []
    for i in xrange((max - max2)/2):
        plan.append(max_party*2)
    if (max - max2)%2:
        plan.append(max_party)

    for i, p in enumerate(P):
        if i != argmax and i != argmax2:
            plan.extend([chr(i+65)]*p)

    for i in xrange(max2):
        plan.append(max_party + max2_party)

    return ' '.join(plan)

T = int(stdin.readline())
for t in xrange(1,T+1):
    N = int(stdin.readline())
    P = map(int, stdin.readline().split())
    print 'Case #{}: {}'.format(t, each_case(N, P))
