from collections import defaultdict

def rl():
    return map(int,raw_input().split())


def f1(x,y):
    return sum([max(y-v,0) for v in x])

def ok(b,n,x,s,y):
    need = f1(x[:s],y) + f1(x[s:],y+1)
    return need <= b

def go(b,n,x,s):
    if len(x) < 37:
        x = x + [0]*(37-len(x))

    x = sorted(x)

    lo = min(x)
    hi = max(x)

    while lo < hi:
        mid = (lo+hi+1)/2
        if ok(b,n,x,s,mid):
            lo = mid
        else:
            hi = mid-1

    y = lo
    #print "s =",s,"y =",y
    return f1(x[:s],y)*36.0/s-(f1(x[:s],y) + f1(x[s:],y+1))

def solve(b,n,x):
    ans = 0.0
    for s in range(1,37):
        currAns = go(b,n,x,s)
        ans = max(ans,currAns)
    return ans

def main():
    T, = rl()
    for t in range(1,T+1):
        b,n = rl()
        x = rl()
        ans = solve(b,n,x)

        print "Case #%d: %.10f"%(t,ans)
    

main()