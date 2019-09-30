def solve2(D, a):
    return pow(2 * D / a, 0.5)

def solve():
    D, N, A = raw_input().split()
    D = float(D)
    N = int(N)
    A = int(A)
    others = []
    for i in xrange(N):
        others.append(map(float, raw_input().split()))
    t_D = 0
    for i in xrange(1, N):
        t, x = others[i]
        if x >= D:
            t_pre, x_pre = others[i - 1]
            v = (x - x_pre) / (t - t_pre)
            t_D = t + (D - x) / v
    ans = []
    for ai in map(float, raw_input().split()):
        ans.append(str(max(solve2(D, ai), t_D)))
    return '\n' + '\n'.join(ans)

T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
