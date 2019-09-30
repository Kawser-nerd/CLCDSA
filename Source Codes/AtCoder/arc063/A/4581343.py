S = input()
Slen = len(S)
cnt = 0
index = 0
if S[0] == "B":
    while index <= Slen-2:
        if S[index] == "B" and S[index+1] == "W":
            cnt += 1
            index += 2
        else:
            index += 1
    if S[-1] == "W":
        print(str(cnt*2-1))
    else:
        print(str(cnt*2))
else:
    while index <= Slen-2:
        if S[index] == "W" and S[index+1] == "B":
            cnt += 1
            index += 2
        else:
            index += 1
    if S[-1] == "B":
        print(str(cnt*2-1))
    else:
        print(str(cnt*2))