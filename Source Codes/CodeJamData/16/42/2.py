import itertools

def eval_p(p_set):
    k = len(p_set)
    dp = (k+1) * [0.0]
    dp[0] = 1.0

    for p in p_set:
        dp_new = (k+1) * [0.0]
        dp_new[0] = (1-p) * dp[0]
        for j in range(1, k+1):
            dp_new[j] = p * dp[j-1] + (1-p) * dp[j]
        dp = dp_new

    return dp[k // 2]


def run():
    n, k = tuple(int(x) for x in input().split())
    ps = list(sorted(float(x) for x in input().split()))
    max_p = 0.0
    max_set = None
    for j in range(k+1):
        p = eval_p(ps[:j] + ps[-(k-j):])
        if p > max_p:
            max_p = p
    for j in range(n+1 - k):
        p = eval_p(ps[j:j+k])
        if p > max_p:
            max_p = p
    return max_p


tc = int(input())
for i in range(tc):
    res = run()
    print("Case #%d: %0.9f" % (i+1, res))
