import sys
from bisect import bisect_right
from operator import itemgetter


def meet_in_the_middle(a: list, limit: int) -> tuple:
    from bisect import bisect_left
    first_v, first_w, second_v, second_w = [], [], [], []

    for items, v_append, w_append in (
            (a[:len(a)//2], first_v.append, first_w.append),
            (a[len(a)//2:], second_v.append, second_w.append)
    ):
        enumerated = [(0, 0)]
        for v, w in items:
            enumerated += [(w+_w, v+_v) for _w, _v in enumerated]

        enumerated.sort()
        enumerated[bisect_left(enumerated, (limit, float("inf"))):] = [(limit+1, 0)]
        max_v = -1
        for (cw, cv), (nw, _) in zip(enumerated, enumerated[1:]):
            if cw < nw and max_v < cv:
                v_append(cv)
                w_append(cw)
                max_v = cv

    return (first_v, first_w), (second_v, second_w)


N, W = map(int, input().split())
a = [list(map(int, l.split())) for l in sys.stdin]

if N <= 30:
    (first_v, first_w), (second_v, second_w) = meet_in_the_middle(a, W)
    ans = 0
    for v, w in zip(first_v, first_w):
        i = bisect_right(second_w, W-w)-1
        new_v = v + second_v[i]
        if ans < new_v:
            ans = new_v
    print(ans)

elif max(a)[0] <= 1000:
    a.sort()
    max_v = sum(v for v, _ in a)
    dp = [0]+[W+1]*max_v
    acc = 0
    for v, w in a:
        acc += v
        for i, to_w, from_w in zip(range(acc, v-1, -1), dp[acc::-1], dp[acc-v::-1]):
            if to_w > from_w + w:
                dp[i] = from_w + w
    for i, w in zip(range(max_v, -1, -1), dp[::-1]):
        if w <= W:
            print(i)
            break

else:
    a.sort(key=itemgetter(1))
    dp = [0]*(W+1)
    acc = 0
    for v, w in a:
        acc = acc+w if W > acc+w else W
        for i, to_v, from_v in zip(range(acc, w-1, -1), dp[acc::-1], dp[acc-w::-1]):
            if to_v < from_v + v:
                dp[i] = from_v + v
    print(max(dp))