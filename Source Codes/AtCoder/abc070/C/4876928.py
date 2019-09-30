def gcd(x,y):
    if y==0:
        return x
    else:
        return gcd(y,x%y)

n=int(input())

x=1
for i in range(n):
    c=int(input())
    x=c*x//gcd(c,x)
print(x)