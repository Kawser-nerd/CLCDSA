n,m=map(int,input().split())

if n>m//2:
    print(m//2)
else:
    x=m-2*n
    print(n+x//4)