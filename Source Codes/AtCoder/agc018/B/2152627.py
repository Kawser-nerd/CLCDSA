from collections import defaultdict
from operator import itemgetter


def sub(prefers, canceled):
    res = defaultdict(int)
    for pref in prefers:
        p = pref[-1]
        while p in canceled:
            pref.pop()
            p = pref[-1]
        res[p] += 1

    return max(res.items(), key=itemgetter(1))


def solve(m, prefers):
    canceled = set()
    ans = float('inf')
    for _ in range(m):
        s, c = sub(prefers, canceled)
        canceled.add(s)
        ans = min(ans, c)
    return ans


n, m = map(int, input().split())
prefers = [list(reversed(list(map(int, input().split())))) for _ in range(n)]

print(solve(m, prefers))