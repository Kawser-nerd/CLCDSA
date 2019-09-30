a,b=map(int,input().split());a,b=map(abs,[a,b])
if a>b:
    print("Bug")
elif a<b:
    print("Ant")
else:
    print("Draw")