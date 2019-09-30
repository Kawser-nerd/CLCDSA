n,a,b = map(int,input().split())
if a>b:
    print(0)
    exit()
if n==1:
    if a==b:
        print(1)
    else:
        print(0)
    exit()
print((b-a)*(n-2)+1)