T = int(raw_input())
for t in xrange(T):
    A = int(raw_input())
    ans = []
    for i in xrange(4):
        s = raw_input()
        if i + 1 == A: ans = map(int, s.split())
    A = int(raw_input())
    ans2 = []
    for i in xrange(4):
        s = raw_input()
        if i+1 == A: ans2 = map(int, s.split())
    ans = [i for i in ans if i in ans2]
    y = "Volunteer cheated!"
    if len(ans) == 1: y = str(ans[0])
    elif len(ans) > 1: y = "Bad magician!"

    print "Case #%d: %s" % (t+1, y)
