def f(a,b):
    a,b=min(a,b),max(a,b)
    if b%a==0:
        return (2*b//a-1)*a
    else:
        return 2*a*(b//a)+f(a,b%a)

n,x=map(int,input().split())
print(n+f(x,n-x))