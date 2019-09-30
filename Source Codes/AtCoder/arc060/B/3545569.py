import math
def f(b,n):
    if n<b:
        return n
    else:
        return f(b,n//b)+(n%b)
N=int(input())
S=int(input())
if N==S:
    print(N+1)
else:
    for b in range(2,int(math.sqrt(N))+2):
        if f(b,N)==S:
            print(b)
            exit()
    ans=10**13
    for p in range(1,int(math.sqrt(N))+2):
        if (N-S)%p!=0:
            continue
        b=(N-S)//p+1
        if b<=1:
            continue
        if f(b,N)==S:
            ans=b
    if ans==10**13:
        print(-1)
    else:
        print(ans)