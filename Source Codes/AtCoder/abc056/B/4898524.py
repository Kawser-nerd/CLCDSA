w,a,b = map(int,input().split())
if b > a :
    ans = b - a - w
else:
    ans = a - b - w    
if ans < 0:
    print(0)
else:
    print(ans)