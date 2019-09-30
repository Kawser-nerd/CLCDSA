tt = int(raw_input())
for t in xrange(1, tt+1):
    s = raw_input().strip()
    ans = s[0]
    signat = [s[0]+s[0]]
    for i in xrange(1,len(s)):
        if s[i] < signat[i-1][0]:
            ans = ans + s[i]
            signat.append(signat[i-1])
        elif s[i] > signat[i-1][0]:
            ans = s[i] + ans
            signat.append(s[i]+signat[i-1][0])
        elif s[i] < signat[i-1][1]:
            ans = ans + s[i]
            signat.append(signat[i-1])
        else:
            ans = s[i] + ans
            signat.append(signat[i-1])
    print 'Case #%d: %s' % (t, ans)