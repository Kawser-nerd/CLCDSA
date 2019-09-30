import bisect
n,m=map(int,input().split())
x,y=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=a[0]
d=0
h=0
while n:
    if d==0:
        c+=x
        e=bisect.bisect_left(b,c)
        if e!=m:
            c=b[e]
            h+=1
            d=1
        else:
            break
    else:
        c+=y
        f=bisect.bisect_left(a,c)
        if f!=n:
            c=a[f]
            h+=1
            d=0
        else:
            break
print((h+d)//2)