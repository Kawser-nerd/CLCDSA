def solve(n,l,gs,b):
    if b in gs:
        return "IMPOSSIBLE"
    if l==1:
        return "0 ?"
    return "?"*(l-1)+" "+"1"*(l-1)+"0?"+"01"*(l-1)

t = int(raw_input())
for cas in xrange(1,t+1):
    n,l= map(int,raw_input().split())
    gs=raw_input().split()
    b=raw_input()
    ans = solve(n,l,gs,b)
    print "Case #{}: {}".format(cas,ans)
