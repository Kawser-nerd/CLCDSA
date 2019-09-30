f = open('C-small-attempt0.in', 'r')
g = open('Csm.txt', 'w')
T = int(f.next().strip())

def solve(A, B, N):
    sh = range(1, N)
    n1 = range(N-1)
    j10 = [10**j for j in sh]
    r10 = [10**(N-j) for j in sh]
    res = 0
    for i in xrange(A, B):
        S = set()
        for j in n1:
            r = i % j10[j]
            d = i / j10[j]
            N = r * r10[j] + d
            if N > i and N <= B:
                S.add(N)
        res += len(S)
    return res


for i in xrange(1,1+T):
    s = f.next().strip().split()
    A = int(s[0])
    B = int(s[1])
    N = len(s[0])
    res = solve(A, B, N)
    g.write('Case #' + str(i) + ': ' + str(res) + '\n')
g.close()