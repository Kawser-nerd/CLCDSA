a,b,c,d,e,f = 0,0,0,0,0,0
n = int(input())
for i in range(n):
    p,q = map(float,input().split())
    if p >= 35:
        a += 1
    if 35 > p >= 30:
        b += 1
    if 30 > p >= 25:
        c += 1
    if q >= 25:
        d += 1
    if p >= 0 and q < 0:
        e += 1
    if p < 0:
        f += 1
print(a,b,c,d,e,f)