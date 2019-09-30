import math

p2=[2**i for i in range(41)]

def gcd(a,b):
    if b==0: return a
    return gcd(b,a%b)

T=input()
for t in range(T):
    p,q=map(int,raw_input().split("/"))
    d=gcd(p,q)
    p/=d
    q/=d
    r=1
    ans=-1
    for i in range(41):
        if p>=q:
            ans=i
            break
        p*=2
    if q not in p2:
        print "Case #%d: impossible"%(t+1)
    else:
        print "Case #%d: %d"%(t+1,ans)
        
