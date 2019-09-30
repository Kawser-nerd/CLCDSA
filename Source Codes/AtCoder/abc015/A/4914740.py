A = input()
B = input()
if A.islower() and B.islower():
    C = len(A)
    D = len(B)
    if C > D:
        print(A)
    elif D > C:
        print(B)