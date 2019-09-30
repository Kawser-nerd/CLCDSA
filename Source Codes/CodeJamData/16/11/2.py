def sol(s):
    r = [s[0]]
    for c in s[1:]:
        if c < r[0]:
            r.append(c)
        else:
            r.insert(0, c)
    return ''.join(r)

t = input()
for i in xrange(t):
    a = raw_input()
    print "Case #%d:" % (i + 1), sol(a)
