a = int(input())
b = a*(10**1000)*a*(10**1000)
c = (a*(10**1000)+(10**1000-1))*(a*(10**1000)+(10**1000-1))
ans = b
s = 2
while True:
    if s>len(str(b)):
        break
    d = 10**s
    k1 = b//d
    k2 = b%d
    if k2==0:
        z = k1*d
        if z <= c:
            ans = z//d
    else:
        z = (k1+1)*d
        if z <= c:
            ans = z//d
    s = s+2
print(ans)