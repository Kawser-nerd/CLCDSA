def solve(n,r,p,s):
    poss = []
    for i in "RPS":
        m = lex(i,n)
        cr=cp=cs=0
        for j in m:
            if j=='R':
                cr+=1
            if j=='S':
                cs+=1
            if j=='P':
                cp+=1
        if(cr==r and cs==s and cp==p):
            poss.append(m)
    if(len(poss)==0):
        return "IMPOSSIBLE"
    return min(poss)
        
beats = {
        "R": "S",
        "S": "P",
        "P": "R"
        }

def lex(c,n):
    if n==0:
        return c
    p1 = lex(c,n-1)
    p2 = lex(beats[c],n-1)
    if p1<p2:
        return p1+p2
    return p2+p1

t = int(raw_input())
for cas in xrange(1,t+1):
    ans = solve(*map(int,raw_input().split()))
    print "Case #{}: {}".format(cas,ans)
