n=int(input())
a=list(map(int,input().split()))
a.sort()
if n%2==1 and a[0]!=0:
    print(0)
else:
    if n%2==1 and a[0]==0:
        a.pop(0)
    d=(0 if n%2==1 else 1)
    for i in range(n//2):
        if a[2*i]!=2*(i+1)-d or a[2*i+1]!=2*(i+1)-d:
            print(0)
            break
    else:
        print(2**(n//2)%(10**9+7))