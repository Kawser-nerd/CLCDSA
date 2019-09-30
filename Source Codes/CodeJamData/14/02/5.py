def solve(c, f, x):
    t, speed = 0.0, 2.0
    while (x - c) / speed > x / (speed + f):
        t += c / speed
        speed += f
    return t + x / speed

T = input()
for i in xrange(T):
    [c, f, x] = map(float, raw_input().split())
    print 'Case #%d: %.7f' % (i + 1, solve(c, f, x))
