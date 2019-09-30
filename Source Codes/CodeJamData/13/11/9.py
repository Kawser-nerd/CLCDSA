
def paint_needed(r,n): return (2*r+1+2*(n-1))*n

T = int(input())
for test in range(1,T+1):
    r, t = [ int(x) for x in input().split() ]
    lo, hi = 1, t+1
    while hi-lo>1:
        med = (hi+lo) // 2
        if paint_needed(r,med) <= t: lo = med
        else: hi = med
    print('Case #{}: {}'.format(test,lo))
