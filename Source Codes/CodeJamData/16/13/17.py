#!/usr/bin/python3
import sys

def find_longest(u, forb, rev):
    ans = 0
    if u not in rev:
        return 1
    for x in rev[u]:
        if x == forb:
            continue
        ans = max(ans, find_longest(x, -1, rev))
    return 1 + ans

def solve(n, p):
    dead = set()
    best = 0
    special_sum = 0
    rev = dict()
    for i, x in enumerate(p):
        if x not in rev:
            rev[x] = []
        rev[x].append(i + 1)
    #
    for i in range(1, n + 1):  # Kid i under consideration
        # Find his cycle.
        if i in dead:
            continue
        seen = dict()
        cnt = 1
        j = i
        while j not in seen:
            seen[j] = cnt
            cnt += 1
            j = p[j - 1]
        # print(seen, j, cnt)
        cyc_len = cnt - seen[j]
        if cyc_len > 2:
            best = max(best, cyc_len)
            for x in seen:
                dead.add(x)
        else:
            # Cycle of length 2! Yay!
            u, v = j, p[j-1]
            if u in dead:
                continue
            # print(u, v)
            dead.add(u)
            dead.add(v)
            special_sum += find_longest(u, v, rev) + find_longest(v, u, rev)
    return max(best, special_sum)

if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for case_num in range(1, t+1):
        n = int(sys.stdin.readline())
        p = [int(x) for x in sys.stdin.readline().split()]
        print('Case #{0}: {1}'.format(case_num, solve(n, p)))
