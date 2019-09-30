def int2base(x,b):
    at=1
    ans=0
    for dig in x:
        ans+=at*dig
        at*=b
    return ans

def get(n,j):
    res = []
    sub=n/2
    divs = [str(i**sub+1) for i in xrange(2,11)]
    for i in xrange(j):
        strdiv = ("1{0:0>"+str(sub-2)+"b}1").format(i)
        res.append(strdiv+strdiv)
    return res,divs

t=int(raw_input())
n,j=map(int,raw_input().split())
res,divs=get(n,j)
print "Case #1:"
for i in res:
    print i," ".join(divs)

