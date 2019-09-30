from collections import Counter
from operator import itemgetter

def sub(prefers, canceled):
    res = Counter()
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
    for _ in [0] * m:
        s, c = sub(prefers, canceled)
        canceled.add(s)
        ans = min(ans, c)
    return ans

if __name__ == '__main__':
    N, M = map(int, input().split())
    A = [list(map(int, input().split()))[::-1] for _ in [0] * N]
    print(solve(M, A))