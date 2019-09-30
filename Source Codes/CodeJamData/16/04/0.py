def int2base(x,b):
    at=1
    ans=0
    for dig in x:
        ans+=at*dig
        at*=b
    return ans

def fill(li,n):
    i=0
    while len(li)<n:
        if i not in li:
            li.append(i)
        i+=1

t=int(raw_input())
for cas in xrange(1,t+1):
    k,c,s=map(int,raw_input().split())
    if c*s<k:
        print "Case #{}: IMPOSSIBLE".format(cas)
        continue
    digs = xrange(k)
    ans = []
    cur=[]
    for i in digs:
        if(len(cur)==c):
            ans.append(int2base(cur,k)+1)
            cur=[]
        cur.append(i)
    while(len(cur)<c):
        cur.append(0)
    ans.append(int2base(cur,k)+1)
    print "Case #{}: {}".format(cas," ".join(map(str,ans)))

