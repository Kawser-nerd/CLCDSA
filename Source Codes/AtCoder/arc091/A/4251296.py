n,m=map(int,input().split())
if n==1 and m==1:
    print(1)
elif n==1  or m==1:
    print(max(max(n,m)-2,0))
else:
    print((n-2)*(m-2))