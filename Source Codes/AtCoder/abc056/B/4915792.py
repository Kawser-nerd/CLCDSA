w,a,b=map(int,input().split())

x=min(a,b)
y=max(a,b)

if x+w>=y:
    print(0)
else:
    print(y-x-w)