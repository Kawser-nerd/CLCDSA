a,b = map(abs,map(int,input().split()))
if a < b:
    print("Ant")
elif a == b:
    print("Draw")
else:
    print("Bug")