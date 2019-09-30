NL = [int(x) for x in str(input())]
if NL[0] == 1 and sum(NL) == 1:
    print(10)
else:
    print(sum(NL))