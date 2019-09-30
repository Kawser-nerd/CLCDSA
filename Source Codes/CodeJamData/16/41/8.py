
def make(i, n, cur):
    if i == n:
        return cur

    ret = ''
    for c in cur:
        a, b = None, None
        if c == 'P':
            a, b = 'P', 'R'
        elif c == 'R':
            a, b = 'R', 'S'
        elif c == 'S':
            a, b = 'P', 'S'
        l1 = make(i + 1, n, a)
        l2 = make(i + 1, n, b)
        if l1 < l2:
            ret += l1
            ret += l2
        else:
            ret += l2
            ret += l1
    return ret

T = int(raw_input())
for t in xrange(T):
    N, R, P, S = map(int, raw_input().split())
    opt = 'IMPOSSIBLE'
    answers = [
        make(0, N, 'R'),
        make(0, N, 'P'),
        make(0, N, 'S'),
    ]
    for ans in answers:
        if ans.count('P') == P and ans.count('R') == R and ans.count('S') == S:
            opt = ans
    print 'Case #%d: %s' % (t+1, opt)
