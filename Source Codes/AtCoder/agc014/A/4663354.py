a,b,c = map(int,input().split())
if a%2==1 or b%2==1 or c%2==1:
    print(0)
    exit()
elif a==b==c:
    print(-1)
    exit()
def f(a,b,c):
    cnt = 0
    while True:
        if a%2==0 and b%2==0 and c%2==0:
            a_ = b//2+c//2
            b_ = a//2+c//2
            c_ = a//2+b//2
            a,b,c=a_,b_,c_
            cnt+=1
        else:
            break
    return cnt
print(f(a,b,c))