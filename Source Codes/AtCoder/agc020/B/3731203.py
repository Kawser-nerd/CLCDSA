k = int(input())
a = list(map(int,input().split()))

#??????n???????????
def g(n,a,k):
    for i in range(k):
        n = n - (n%a[i])
    return n

#print(g(8,a,k))

s = 0
t = 2 + k*max(a)
while t-s > 1:
    m = (s+t)//2
    if g(m,a,k)> 2:
        t = m
    else:
        s = m
    
p = 0
q = 2+k*max(a)
while q-p > 1:
    m = (p+q)//2
    if g(m,a,k) >= 2:
        q = m
    else:
        p = m

c = 1
if g(s,a,k) == 2:
    res = s
elif g(t,a,k) == 2:
    res = t
else:
    c = -1

if g(q,a,k) == 2:
    res2 = q
elif g(p,a,k) == 2:
    res2 = p
else:
    c = -1

if c == 1:
    print(res2,res)
else:
    print(-1)