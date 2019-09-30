m=10**9+7
def f(a,b):
    r=1
    for i in range(b):
        r=r*(n+k-1-i)*pow(i+1,m-2,m)%m
    return r
n=int(input())
k=int(input())
print(f(n,k))