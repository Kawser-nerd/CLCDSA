n=int(input())
now=(0,0,0)
result=True
for i in range(n):
    t,a,b=[int(i) for i in input().split()]
    time=t-now[0]
    x=abs(a-now[1])
    y=abs(b-now[2])
    if (x+y-time)%2!=0 or (x+y)>time:
        result=False
    else:
        now=(t,a,b)
if result:
    print("Yes")
else:
    print("No")