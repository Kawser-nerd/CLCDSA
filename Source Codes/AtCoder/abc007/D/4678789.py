p=[0,1,2,3,4,4,5,6,7,8,8]
def f(a):
    c=0
    a=str(a)
    h=1
    for i in range(len(a)):
        d=int(a[i])
        c+=p[d]*(8**(len(a)-i-1))*h
        if d==4 or d==9:
            h=0
    else:
        return int(a)-c+1
a,b=map(int,input().split())
print(f(b+1)-f(a))