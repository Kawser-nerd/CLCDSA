s = raw_input()
cases = int(s)
for case in range(cases):
    print 'Case #%d:' % (case+1),
    s = raw_input()
    seens = [-1 for i in range(128)]
    seen = 1
    x = []
    for ch in s:
        if seens[ord(ch)] == -1:
            seens[ord(ch)] = seen
            if seen == 1:
                seen = 0
            elif seen == 0:
                seen = 2
            else:
                seen = seen + 1
        x = x + [seens[ord(ch)]]
    if seen == 1:
        seen = 2
    elif seen == 0:
        seen = 2
    z=0
    if 0:
        print '%d' % 0
    else:
        while len(x):
            z = z * seen + x[0]
            x = x[1:len(x)]
        print '%d' % z