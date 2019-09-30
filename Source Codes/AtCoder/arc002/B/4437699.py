month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
S = list(map(int, input().split("/")))
while S[0] / S[1] / S[2] != S[0] // S[1] // S[2]:
    Y = S[0]
    flag = False
    if Y % 400 == 0:
        flag = True
    elif Y % 100 == 0:
        flag = False
    elif Y % 4 == 0:
        flag = True

    m = 0
    if S[1] == 2 and flag:
        m = 1

    S[2] += 1
    if month[S[1] - 1] + m < S[2]:
        S[2] = 1
        S[1] += 1
        if S[1] == 13:
            S[1] = 1
            S[0] += 1

T = [str(S[0])]
if S[1] // 10 == 0:
    T.append("0" + str(S[1]))
else:
    T.append(str(S[1]))
if S[2] // 10 == 0:
    T.append("0" + str(S[2]))
else:
    T.append(str(S[2]))
print("/".join(T))