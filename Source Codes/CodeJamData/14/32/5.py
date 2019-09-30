from string import ascii_lowercase as alph
for t in xrange(input()):
    n = input()
    sets = [''.join(s[i] for i in xrange(len(s)) if i==0 or s[i]!=s[i-1]) for s in raw_input().split(' ')]
    cnt = dict((c,sum(s.count(c) for s in sets)) for c in alph)
    res = 0
    impossible = False
    loose = dict((c,0) for c in alph)
    rest = []
    begs = {}
    ends = {}
    for s in sets:
        if s[0] == s[-1] and len(s)>1:
            impossible = True
            break
        for c in s[1:-1]:
            if cnt[c] > 1:
                impossible = True
                break
        if s[0] == s[-1]:
            loose[s[0]] += 1
        else:
            rest.append(s[0]+s[-1])
            if s[0] in begs or s[-1] in ends:
                impossible = True
            begs[s[0]] = len(rest)-1
            ends[s[-1]] = len(rest)-1
    if impossible:
        print 'Case #%d: 0' % (t+1)
        continue
    done = [False] * len(rest)
    res = 1
    parts = 0
    MOD = int(1e9+7)
    factorial = [1]
    for i in xrange(1,101):
        factorial.append((factorial[-1] * i) % MOD)
    for i,s in enumerate(rest):
        if done[i]:
            continue
        done[i] = True
        j = i
        while rest[j][0] in ends:
            res = (res * factorial[loose[rest[j][0]]]) % MOD
            loose[rest[j][0]] = 0
            j = ends[rest[j][0]]
            if done[j]:
                impossible = True
                break
            done[j] = True
        res = (res * factorial[loose[rest[j][0]]]) % MOD
        loose[rest[j][0]] = 0
        j = i
        while rest[j][1] in begs:
            res = (res * factorial[loose[rest[j][1]]]) % MOD
            loose[rest[j][1]] = 0
            j = begs[rest[j][1]]
            if done[j]:
                impossible = True
                break
            done[j] = True
        res = (res * factorial[loose[rest[j][1]]]) % MOD
        loose[rest[j][1]] = 0
        parts += 1
    for c in alph:
        if loose[c]:
            res = (res * factorial[loose[c]]) % MOD
            parts += 1
    res = (res * factorial[parts]) % MOD
    if impossible:
        res = 0
    print 'Case #%d: %d' % (t+1, res)
