A = int(input())
B = int(input())
C = int(input())

if A < B < C:
    print(3)
    print(2)
    print(1)
elif A < C < B:
    print(3)
    print(1)
    print(2)
elif B < A < C:
    print(2)
    print(3)
    print(1)
elif B < C < A:
    print(1)
    print(3)
    print(2)
elif C < B < A:
    print(1)
    print(2)
    print(3)
elif C < A < B:
    print(2)
    print(1)
    print(3)