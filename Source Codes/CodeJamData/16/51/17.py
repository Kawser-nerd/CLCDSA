T = input()

from collections import defaultdict

def solve(S):
    dp = [{'' : 0}]
    for i, ch in enumerate(S):
        last = dp[-1]
        nxt = defaultdict(int)
        # print len(last)
        for pre, val in last.iteritems():
            if not (len(S) - i < len(pre)):
                st = pre + ch
                nxt[st] = max(nxt[st], val)
            if pre:
                sc = val + (10 if ch == pre[-1] else 5)
                st = pre[:-1]
                nxt[st] = max(nxt[st], sc)
        dp.append(nxt)
    return max(dp[-1].values())

for i in range(1, T + 1):
    S = raw_input().strip()
    print 'Case #{}: {}'.format(i, solve(S))
