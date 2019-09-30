n=int(input())
a,b=map(int,input().split())
for i in range(n-1):
    e,f=map(int,input().split())
    if (a//e+(1 if a%e!=0 else 0))*f>=b:
        b=f*(a//e+(1 if a%e!=0 else 0))
        a=e*(a//e+(1 if a%e!=0 else 0))
    else:
        a=e*(b//f+(1 if b%f!=0 else 0))
        b=f*(b//f+(1 if b%f!=0 else 0))
print(a+b)