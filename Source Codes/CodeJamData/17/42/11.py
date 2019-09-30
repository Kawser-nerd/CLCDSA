import sys
from collections import defaultdict


def solve():
    n, c, m = map(int, raw_input().strip().split())
    p = [0] * m
    b = [0] * m
    
    users = defaultdict(lambda: 0)
    poses = defaultdict(lambda: 0)

    for i in range(m):
        p[i], b[i] = map(int, raw_input().strip().split())
        users[b[i]] += 1
        poses[p[i]] += 1

    ans = max(users.values())

    s = 0
    for i in range(1, n + 1):
        s += poses[i]
        ans = max(ans, (s + i - 1) / (i))

    promo = 0
    for i in range(n + 1):
        if poses[i] > ans:
            promo += poses[i] - ans

    print ans, promo

if __name__ == '__main__':
    T = int(raw_input())
    for case_idx in xrange(1, T+1):
        sys.stdout.write("Case #{}: ".format(case_idx))
        solve()
