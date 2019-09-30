A,B = map(int,input().split(" "))
if A > 0 and B > 0:
    print(abs(B - A))
elif A < 0 and B < 0:
    print(abs(B - A))
elif A < 0 and B > 0:
    print(B - A - 1)
elif A > 0 and B < 0:
    print(A - B - 1)