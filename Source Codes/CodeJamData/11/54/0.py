from sys import stdin, stderr

def fill(q, m):
    ans = 0
    j = 0
    for i in xrange(len(q)):
        if q[i] in '01':
            ans = 2 * ans + int(q[i])
        else:
            ans = 2 * ans + m[j]
            j += 1
    return ans

def check(num, S):
    k = [(num >> i) & 1 for i in xrange(len(S),-1,-1)]
    S = ['0'] + [z for z in S]
    for i in xrange(len(S)):
        if (S[i] == '?') or (S[i] == str(k[i])):
            dummy = 14
        else:
            return False
    return True

def output(num, k):
    ans = ("Case #%d: " % num)
    digs = []
    while (k > 0):
        digs += [k & 1]
        k >>= 1
    digs.reverse()
    ans += "".join([str(dig) for dig in digs])
    return "".join([str(dig) for dig in digs])

recbadtrials = 0

def f(S):
    global recbadtrials
    if (len(S) == 1):
        return "1"
    if (len(S) == 2):
        return None
    if (S[-2] == '1'):
        return None
    if (S[-1] == '0'):
        g = f(S[:-2])
        if (g == None):
            return None
        return g + "00"
    if (S[-1] == '?'):
        g = f(S[:-2])
        if (g != None):
            return g + "00"
    n = len(S)
    n1 = (n >> 1)
    lf = S[:n1]
    rt = S[n1:]
    n2 = n - n1
    q1 = len([z for z in lf if z == '?'])
    q2 = len([z for z in rt if z == '?'])
    if (q1 <= q2):
        pwr = (1 << q1)
        for w in xrange(pwr):
            m1 = [(w >> i) & 1 for i in xrange(q1)]
            qfl = fill(lf, m1)
            q = qfl << n2
            r = (qfl + 1) <<  n2
            lwr = 0
            upr = r
            while (lwr + 1 < upr):
                mid = (lwr + upr) >> 1
                if mid * mid < q:
                    lwr = mid
                else:
                    upr = mid
            badtrials = 0
            while (upr * upr <= r):
                if (check(upr * upr, S)):
                    return output(k+1, upr * upr)
                badtrials += 1
                if badtrials > recbadtrials:
                    recbadtrials = badtrials
                upr += 1
        return None
    else:
        pwr = (1 << q2)
        lgst = 0
        for z in S:
            if z == '0':
                lgst = 2 * lgst
            else:
                lgst = 2 * lgst + 1
        for w in xrange(pwr):
            m1 = [(w >> i) & 1 for i in xrange(q2)]
            qfl = fill(rt, m1)
            res = 1 << n2
            if (qfl & 7 != 1):
                continue
            stu = 16
            if (qfl & 15 == 1):
                ans = 1
                mod = 8
            else:
                ans = 3
                mod = 8
            while (stu < res):
                # print [ans, mod], [stu, qfl % stu]
                stu = stu << 1
                if (ans * ans) % stu != (qfl % stu):
                    ans += mod
                if (ans * ans) % stu != (qfl % stu):
                    # print "!"
                    # print ((ans - mod) ** 2) % stu
                    # print (ans * ans) % stu
                    # print [ans, mod], [stu, qfl % stu]
                    while (1 == 1):
                        dummy = 17
                mod = mod << 1
            oldans = [ans, mod]
            # print [ans, mod, qfl, res, (ans * ans) % res, qfl % res]
            badtrials = 0
            while (ans * ans <= lgst):
                if (check(ans * ans, S)):
                    return output(k + 1, ans * ans)
                badtrials += 1
                if badtrials > recbadtrials:
                    recbadtrials = badtrials
                ans += mod
            [ans, mod] = [mod - ans, mod]
            # print [ans, mod, qfl, res, (ans * ans) % res, qfl % res]
            while (ans * ans <= lgst):
                if (check(ans * ans, S)):
                    return output(k + 1, ans * ans)
                badtrials += 1
                if badtrials > recbadtrials:
                    recbadtrials = badtrials
                ans += mod
        return None

for k in xrange(int(stdin.readline())):
    S = stdin.readline().strip()
    print >> stderr, k, len(S)
    print "Case #%d: %s" %(k+1, f(S))

print recbadtrials
