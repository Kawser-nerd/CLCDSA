n,p=map(int,input().split())
a = list(map(int,input().split()))
k=0
for a_ in a:
    if not a_%2==0:
        k=1
        break
if k:
    print(1<<(n-1))
else:
    print(0) if p==1 else print(1<<n)