def gcd(a,b):
    return a if b == 0 else gcd(b,a%b)

x,y = map(int,input().split("/"))
k = gcd(x,y)
x //= k; y //= k;

flag = False
for i in range((2*x)//(y**2)-1,10000000000000):
    n = i*y
    m = (n*(n+1))//2 - i*x

    if (n<=0 or m<=0) : continue
    if (n<m) : break

    print(n,m)
    flag = True

if (not flag): print("Impossible")