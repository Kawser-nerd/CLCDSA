a,b=map(int,input().split())
if a==1 and b==1:
    print(1)
elif a==1 or b==1:
    print(max(a,b)-2)
elif a==2 or b==2:
    print(0)
else:
    print(a*b-2*a-2*b+4)