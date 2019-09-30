n,a,b=map(int,input().split())
if b<a:
    print(0)
elif n==1:
    if a==b:
        print(1)
    else:
        print(0)
else:
    print( a+b*(n-1) - (a*(n-1)+b) +1 )