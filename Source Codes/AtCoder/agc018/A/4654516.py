n,k = map(int,input().split())
a = list(map(int,input().split()))
def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
if max(a)<k:
    print('IMPOSSIBLE')
else:
    g = a[0]
    for i in range(n):
        g = gcd(max(g,a[i]),min(g,a[i]))
    if k%g==0:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')