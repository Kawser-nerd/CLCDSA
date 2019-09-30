import math
n=int(input())
s=int(input())

def f(b,n):
    if n<b:
        return n
    else:
        return f(b,n//b)+(n%b)


def abc(N,S):
    if N==S:
        return N+1
    else:
        for b in range(2,int(math.sqrt(N))+2):
            if f(b,N)==S:
                return b
        tmp=-1
        for p in range(1,int(math.sqrt(N))+2):
            if (N-S)%p!=0:
                continue
            b=(N-S)//p+1
            if b<=1:
                continue
            if f(b,N)==S:
                tmp=b
        return tmp
ans=abc(n,s)
print(ans)