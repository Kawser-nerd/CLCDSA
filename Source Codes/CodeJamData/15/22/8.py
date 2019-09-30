def check(q2, q3, q4, num):
    ret = 0
    u4 = min(q4, num)
    ret += u4 * 4
    num -= u4
    u3 = min(q3, num)
    ret += u3 * 3
    num -= u3
    u2 = min(q2, num)
    ret += u2 * 2
    num -= u2
    if num > 0:
        return 0
    return ret

def check1(q1, q2, num):
    ret = 0
    u2 = min(q2, num)
    ret += u2 * 2
    num -= u2
    u1 = min(q1, num)
    ret += u1 * 1
    num -= u1
    if num > 0:
        return 0
    return ret

tt = int(raw_input())
for t in xrange(1, tt+1):
    (r, c, n) = map(int, raw_input().split())
    safe = (r * c + 1) / 2
    if n <= safe:
        ans = 0
    elif r == 1 and c == 1:
        ans = 0
    elif r == 1 or c == 1:
        p = (r+c)-1
        if p % 2 == 0:
            p1 = 1
            p2 = (p-2)/2
            best = check1(p1,p2,r*c-n)
        else:
            p1 = 2
            p2 = (p-3)/2
            best = check1(p1,p2,r*c-n)
            p1 = 0
            p2 = (p-1)/2
            best = max(best,check1(p1,p2,r*c-n))
        ans = p-1 - best
    else:
        if r % 2 == 0 or c % 2 == 0:
            p2 = 2
            p3 = r+c-4
            p4 = ((r-2)*(c-2))/2
            best = check(p2,p3,p4,r*c-n)
        else:
            p2 = 4
            p3 = r+c-6
            p4 = ((r-2)*(c-2)+1)/2
            best = check(p2,p3,p4,r*c-n)
            p2 = 0
            p3 = r+c-2
            p4 = ((r-2)*(c-2)-1)/2
            best = max(best,check(p2,p3,p4,r*c-n))
        ans = r*(c-1) + c*(r-1) - best
    print 'Case #%d: %d' % (t, ans)