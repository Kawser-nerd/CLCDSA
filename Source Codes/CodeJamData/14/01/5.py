def solve():
    i = input() - 1
    a = [map(int, raw_input().split()) for _ in xrange(4)]
    j = input() - 1
    b = [map(int, raw_input().split()) for _ in xrange(4)]

    ans = list(set(a[i]) & set(b[j]))
    if len(ans) == 1:
        return str(ans[0])
    elif len(ans) >= 2:
        return 'Bad magician!'
    else:
        return 'Volunteer cheated!'

T = input()
for i in xrange(T):
    print 'Case #%d: %s' % (i + 1, solve())
