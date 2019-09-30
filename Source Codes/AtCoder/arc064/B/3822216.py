def ARC064D():
    s = list(input())
    if s[0] == s[-1]:
        key = 1
    else:
        key = -1

    if len(s) % 2 != 0:
        key *= -1

    if key == 1:
        print("First")
    else:
        print("Second")

ARC064D()