from fractions import Fraction

def eliminate(matrix):
    n, m = len(matrix), len(matrix[0]) - 1
    for r in xrange(m):
        i = r
        while matrix[i][r] == 0:
            i += 1
        matrix[r], matrix[i] = matrix[i], matrix[r]
        s = Fraction(matrix[r][r])
        for j in xrange(m + 1):
            matrix[r][j] /= s
        for i in xrange(n):
            if i != r and matrix[i][r] != 0:
                s = matrix[i][r]
                for j in xrange(m + 1):
                    matrix[i][j] -= matrix[r][j] * s
    for i in xrange(m, n):
        assert matrix[i][m] == 0
    return [matrix[i][m] for i in xrange(m)]

WORDS = 'ZERO ONE TWO THREE FOUR FIVE SIX SEVEN EIGHT NINE'.split()
for t in xrange(1, input() + 1):
    s = raw_input()
    eqns = []
    for c in xrange(26):
        C = chr(ord('A') + c)
        eqn = []
        for i in xrange(10):
            eqn.append(WORDS[i].count(C))
        eqn.append(s.count(C))
        eqns.append(eqn)
    x = eliminate(eqns)
    ans = ''
    for i in xrange(10):
        if x[i] > 0:
            ans += chr(48 + i) * int(x[i])
    print "Case #{}: {}".format(t, ans)
