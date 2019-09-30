from math import*
n=factorial(int(input()))

def dv(n):
    if n==1:
        return 1
    divisorsNum=1
    i=2
    while i*i<=n:
        cnt=1
        while n%i==0:
            cnt+=1
            n//=i
        divisorsNum*=cnt
        i+=1
    return divisorsNum*2
mod=(10**9+7)
print(dv(n)%mod)