S = list(input())
Flag = 0

if (S[0] == "A"):
    Flag += 1

if (S[2:-1].count("C") == 1):
    Flag += 1

if (Flag == 2):
    S.remove("A")
    S.remove("C")
    if (str(S).islower()):
        Flag += 1

if (Flag == 3):
    print("AC")
else:
    print("WA")