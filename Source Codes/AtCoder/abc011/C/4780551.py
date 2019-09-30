n=int(input())
ng1=int(input())
ng2=int(input())
ng3=int(input())
ng=[ng1,ng2,ng3]
if n in ng:
    print("NO")
    exit()
for _ in range(100):
    if not n-3 in ng and n>=3:
        n-=3
    elif not n-2 in ng and n>=2:
        n-=2
    elif not n-1 in ng and n>=1:
        n-=1
    if n==0:
        print("YES")
        exit()
print("NO")