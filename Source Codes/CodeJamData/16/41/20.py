T = input()

def win(x, y):
    if x == y:
        return None
    if {x, y} == {'R', 'P'}:
        return 'P'
    if {x, y} == {'P', 'S'}:
        return 'S'
    return 'R'

def simul(s):
    if len(s) == 1:
        return True
    nr = ''
    for i in range(len(s) / 2):
        res = win(s[2 * i], s[2 * i + 1])
        if res is None: return False
        nr += res
    return simul(nr)

MEMO = {
    (1, 1, 0): 'PR',
    (1, 0, 1): 'RS',
    (0, 1, 1): 'PS',
}

def recur(N, R, P, S):
    global MEMO
    if (R, P, S) in MEMO: return MEMO[(R, P, S)]

    # print N, R, P, S
    if N % 3 == 1:
        if R - 1 == P == S:
            a, b = recur(N / 2, R / 2, R / 2 - 1, R / 2), recur(N / 2, R / 2, R / 2, R / 2 - 1)
        if R == P - 1 == S:
            a, b = recur(N / 2, P / 2 - 1, P / 2, P / 2), recur(N / 2, P / 2, P / 2, P / 2 - 1)
        if R == P == S - 1:
            a, b = recur(N / 2, S / 2 - 1, S / 2, S / 2), recur(N / 2, S / 2, S / 2 - 1, S / 2)
    else:
        if R == P == S + 1:
            a, b = recur(N / 2, S / 2 + 1, S / 2, S / 2), recur(N / 2, S / 2, S / 2 + 1, S / 2)
        if R == P + 1 == S:
            a, b = recur(N / 2, P / 2 + 1, P / 2, P / 2), recur(N / 2, P / 2, P / 2, P / 2 + 1)
        if R + 1 == P == S:
            a, b = recur(N / 2, R / 2, R / 2 + 1, R / 2), recur(N / 2, R / 2, R / 2, R / 2 + 1)

    ans = a + b if a < b else b + a
    MEMO[R, P, S] = ans
    return ans

from itertools import combinations, product
from collections import Counter

def solve(N, R, P, S):
    if abs(R - P) >= 2 or abs(P - S) >= 2 or abs(S - R) >= 2:
        return 'IMPOSSIBLE'
    # print N,R,P,S
    ans = recur(2**N, R, P, S)
    c = Counter(ans)
    assert not (c['R'] != R or c['P'] != P or c['S'] != S)
    return ans
    # for order in product('PRS', repeat=2 ** N):
    #     c = Counter(order)
    #     if c['R'] != R or c['P'] != P or c['S'] != S:
    #         continue
    #     # print order
    #     if simul(order):
    #         return ''.join(order)
    return 'IMPOSSIBLE'

for i in range(1, T + 1):
    N, R, P, S = map(int, raw_input().strip().split())
    print 'Case #{}: {}'.format(i, solve(N, R, P, S))
