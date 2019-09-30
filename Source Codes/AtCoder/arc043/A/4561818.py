n,a,b=map(int,input().split())
s=[int(input())for i in range(n)]
d=max(s)-min(s)
if d!=0:
    print(b/d,a-(sum(s)/n)*(b/d))
else:
    if b!=0:
        print(-1)
    else:
        print(1,a-s[0])