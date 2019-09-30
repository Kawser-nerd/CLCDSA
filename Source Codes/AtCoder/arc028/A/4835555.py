n,a,b=map(int,input().split())
c=n%(a+b)
if c==0:
    print("Bug")
elif c-a>0:
    print("Bug")
else:
    print("Ant")