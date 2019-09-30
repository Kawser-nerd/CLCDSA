def gcd(x,y):
    if(x < y): x,y = y,x
    if(y == 0): return x
    return gcd(y,x % y)


n,x = map(int,input().split())

g = gcd(n,x)

n //= g

print((3*n-3)*g)