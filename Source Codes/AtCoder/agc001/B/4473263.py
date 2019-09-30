n,x = map(int,input().split())

def gcd(a,b):
    if a%b == 0:
        return b
    else:
        return gcd(b,a%b)

k = gcd(n,x)
if k == 1:
    print((n-1)*3)
else:
    print((int(n/k)-1)*3*k)