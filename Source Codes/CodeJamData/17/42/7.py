num_testcases = int(input())

def can_do(ts, l):
    s = 0
    for i, k in enumerate(ts):
        s += k
        if s > (i+1) * l:
            return False
    return True


for testcase_num in range(1, num_testcases + 1):
    n, c, m = tuple(int(x) for x in input().split())
    tkts_per_customer = [0] * c
    tkts_per_seat = [0] * n
    for i in range(m):
        p, b = tuple(int(x) for x in input().split())
        tkts_per_seat[p-1] += 1
        tkts_per_customer[b-1] += 1
    l = 0
    r = 1
    while not can_do(tkts_per_seat, r):
        l = r
        r *= 2
    while l < r-1:
        if can_do(tkts_per_seat, (l+r) // 2):
            r = (l + r) // 2
        else:
            l = (l + r) // 2
    res = max(r, max(tkts_per_customer))
    res2 = max(0, max(tkts_per_seat) - res)
    print("Case #%d: %s %s" % (testcase_num, res, res2))
