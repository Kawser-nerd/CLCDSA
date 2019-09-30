import sys
sys.setrecursionlimit(10**6)
def solve(n):
    if(n<=10):
        return n
    if(n%10==0):
        return solve(n-1)+1
    x=str(n)
    p=len(x)
    a=x[p/2:]
    b=x[:p/2]
    q=1
    while(q<=n):
        q*=10
    q/=10
    tmp=(int(b[::-1])-1)
    if(tmp==0):
        return solve(q)+int(a)
    else:
        return solve(q)+int(a)+tmp+1


tcases=int(raw_input())
for cas in xrange(1,tcases+1):
    n=int(raw_input())
    print "Case #{}: {}".format(cas,solve(n))
