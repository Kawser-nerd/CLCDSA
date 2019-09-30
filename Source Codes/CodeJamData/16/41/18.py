import sys

in_file = open('a-large.in', 'r')
out_file = open('a.out', 'w')
sys.stdin = in_file
sys.stdout = out_file

def calc(winner):
    if winner == 'R':
        return 'S'
    if winner == 'S':
        return 'P'
    if winner == 'P':
        return 'R'
    assert False

def check(n, winner):
    if n == 0:
        return winner
    other = calc(winner)
    l = check(n - 1, winner)
    r = check(n - 1, calc(winner))
    if l < r:
        return l + r
    else:
        return r + l

T = int(raw_input())
for t in xrange(T):
    n, R, P, S = map(int, raw_input().split())
    ans = None
    for win in ('R', 'P', 'S'):
        best = check(n, win)
        if best.count('R') != R or best.count('P') != P or best.count('S') != S:
            continue
        if ans == None or best < ans:
            ans = best
    if ans == None:
        ans = 'IMPOSSIBLE'
    print 'Case #%d: %s' % (t + 1, ans)

in_file.close()
out_file.close()
