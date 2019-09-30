
def read_array(convertor=None):
    ret = raw_input().split()
    if convertor: ret = map(convertor, ret)
    return ret


def construct(i, k, K, s):
    ret = ""
    while i:
        m = i % k
        ret = K[m] + ret
        i /= k
    while len(ret) < s:
        ret = K[0] + ret
    return ret


def need_give(st, L):
    lst = len(st)
    start = 0
    ans = 0
    while start != -1:
        start = st.find(L, start)
        if start != -1:
            ans += 1
            start += 1
    return ans


def main():
    for t in range(1, 1+input()):
        k, l, s = read_array(int)
        K = raw_input() # keyboard
        L = raw_input() # expected word

        need = 0
        all_give = 0
        for i in xrange(k ** s):
            st = construct(i, k, K, s)
            give = need_give(st, L)
            #print 'st, L, give', st, L, give
            need = max(need, give)
            all_give += give

        #print 'need', need
        #print 'all_give', all_give
        ans = ((need * (k**s)) - all_give) / float(k**s)

        print "Case #%d: %f" % (t, ans)





    pass



main()
