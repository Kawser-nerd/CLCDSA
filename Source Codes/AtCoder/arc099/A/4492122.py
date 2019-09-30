n,k=map(int,input().split())
li=list(map(int,input().split()))
b=n-k
if n==k:
    print(1)
elif b%(k-1)==0:
    print(1+(b//(k-1)))
else:
    print(2+(b//(k-1)))