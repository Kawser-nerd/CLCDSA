s = input()
S = list(s)
f = False
k = 1
flag = False
while len(S) > 2:
    if k == len(S) - 1:
        if flag:
            k = 1
            flag = False
            continue
        break
    if S[k - 1] != S[k + 1]:
        S.pop(k)
        f = not f
        flag = True
    else:
        k += 1
if f:
    print('First')
else:
    print('Second')