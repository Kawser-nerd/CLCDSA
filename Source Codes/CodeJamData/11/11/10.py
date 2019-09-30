def whole_num(frac):
    a = int(frac*100)
    from_100 = 1
    for i in range(2):
        if a % 2 == 0:
            a /= 2
            from_100 *= 2
        if a % 5 == 0:
            a /= 5
            from_100 *= 5
    return 100/from_100

def possible(n, pd, pg):
    if pg == 0:
        return pd == 0
    if pg == 100:
        return pd == 100
    
    pd = float(pd)/100
    pg = float(pg)/100
    a, b = map(whole_num, (pd, pg))
    return a <= n

def solve(case):
    n, pd, pg = map(int, case.strip().split())
    solution = 'Broken'
    if possible(n, pd, pg):
        solution = 'Possible'
    return solution

if __name__ == "__main__":
    T = int(raw_input())
    for i in range(1, T+1):
        sol = solve(raw_input())
        print "Case #%d: %s" % (i, sol)
