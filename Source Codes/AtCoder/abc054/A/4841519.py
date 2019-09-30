A, B = map(int, input().split())

if A == 1 or B == 1:
    if A == B:
        print("Draw")
    else:
        if A == 1:
            print("Alice")
        else:
            print("Bob")
else:
    if A == B:
        print("Draw")
    elif A > B:
        print("Alice")
    else:
        print("Bob")