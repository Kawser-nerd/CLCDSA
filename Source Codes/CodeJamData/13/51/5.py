
def read_array(convertor=None):
    ret = raw_input().split()
    if convertor: ret = map(convertor, ret)
    return ret


def ok(m, ns, i, B):
    #debug = 0
    if m == 110 and i == 37:
        debug = 1

    need = 0
    for j in range(i):
        need += m - ns[j]
    #    if debug:
    #        print 'jn', j, need

    for j in range(i, len(ns)):
        if m+1 > ns[j]:
            need += m+1 - ns[j]
    #    if debug:
    #        print 'jn', j, need

    #print 'minb', m, i, need, B

    return need <= B


def cal(ns, i, B):
    i += 1
    l = ns[i-1]
    r = 10 ** 19
    if not ok(l, ns, i, B):
        return 0

    #print l, r

    while l <= r:
        m = (l+r) // 2
        if ok(m, ns, i, B):
            l = m + 1
        else:
            r = m - 1

    ans = r
    used = 0
    for j in range(i):
        used += ans - ns[j]
    for j in range(i, len(ns)):
        if ans+1 > ns[j]:
            used += ans+1 - ns[j]

    exp = 0.0
    for j in range(i):
        exp += (ans - ns[j]) * 36. / i
    exp -= used
    #print i, ans, exp
    return exp


def main():
    T = input()
    for _ in range(T):
        B, N = read_array(int)
        ns = read_array(int)
        while len(ns) < 37:
            ns += [0]
        ns += [10**100]
        ns.sort()


        ans = 0.
        for i in range(len(ns)):
            ans = max(ans, cal(ns, i, B))


        print 'Case #%d: %.9f' %(_+1, ans)



main()
