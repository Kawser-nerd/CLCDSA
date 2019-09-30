a,b,c = map(int,input().split())
if a+b==c and a-b==c:
    print("?")
    exit()
elif a+b==c:
    print("+")
    exit()
elif a-b==c:
    print("-")
    exit()
else:
    print("!")