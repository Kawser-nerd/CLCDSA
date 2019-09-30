def can(r, t, n):
    paint_needed = n*(2*r + 1) + 2*n*(n-1)
    return paint_needed <= t

def solve(r, t):
    lo = 1
    hi = (t+1) // 2
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if can(r, t, mid):
            lo = mid
        else:
            hi = mid - 1
    return lo

T = int(input())
for tt in range(T):
    r, t = tuple(int(tok) for tok in input().split())
    print('Case #{}: {}'.format(tt+1, solve(r, t)))

