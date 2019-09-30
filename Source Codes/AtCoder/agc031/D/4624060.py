from operator import itemgetter


def get_identity():
    return list(range(1, n + 1))


def composition(ppp, qqq):
    return [ppp[q - 1] for q in qqq]


def reverse_composition(ppp, qqq):
    return [ppp[i] for i, q in sorted(enumerate(qqq), key=itemgetter(1))]


def solve(k, ppp, qqq):
    qp = reverse_composition(qqq, ppp)
    qpq = reverse_composition(qp, qqq)
    qpqp = composition(qpq, ppp)
   
    l, m = divmod(k - 1, 6)
    res = get_identity()
    tmp = qpqp
    while l:
        if l % 2 == 1:
            res = composition(res, tmp)
        tmp = composition(tmp, tmp)
        l >>= 1

    m = (k - 1) % 6
    if m == 0:
        base = ppp
    elif m == 1:
        base = qqq
    elif m == 2:
        base = reverse_composition(qqq, ppp)
    elif m == 3:
        res = composition(res, qqq)
        base = reverse_composition(get_identity(), ppp)
    elif m == 4:
        res = composition(res, qqq)
        res = reverse_composition(res, ppp)
        base = reverse_composition(get_identity(), qqq)
    elif m == 5:
        res = composition(res, qqq)
        res = reverse_composition(res, ppp)
        base = reverse_composition(get_identity(), qqq)
        base = composition(base, ppp)
    else:
        raise NotImplementedError

    ans = composition(res, base)
    ans = reverse_composition(ans, res)
    return ans


n, k = map(int, input().split())
ppp = list(map(int, input().split()))
qqq = list(map(int, input().split()))
print(*solve(k, ppp, qqq))