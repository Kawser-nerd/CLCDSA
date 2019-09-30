E = set(map(int,input().split()))
B = int(input())
L = set(map(int,input().split()))
if E == L:
    print(1)
else:
    s = E & L
    if len(s) == 5:
        if list(L - s)[0] == B:
            print(2)
        else:
            print(3)
    elif len(s) == 4:
        print(4)
    elif len(s) == 3:
        print(5)
    else:
        print(0)