N = input()
A, B, C, D = int(N[0]), int(N[1]), int(N[2]), int(N[3])
OP = ["+", "-"]

ANS = 0
flg = False


for op1 in OP:
    if flg is True:
        break
    ANS = A
    if op1 == "+":
        ANS = ANS + B
    else:
        ANS = ANS - B
    for op2 in OP:
        if flg is True:
            break
        ANS2 = ANS
        if op2 == "+":
            ANS2 = ANS + C
        else:
            ANS2 = ANS - C
        for op3 in OP:
            ANS3 = ANS2
            if op3 == "+":
                ANS3 = ANS2 + D
            else:
                ANS3 = ANS2 - D
            if ANS3 == 7:
                print("%d%s%d%s%d%s%d=7" % (A, op1, B, op2, C, op3, D))
                flg = True
                break