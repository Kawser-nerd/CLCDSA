S = input()
if len(S) % 2 == 0:
    S1 = S[:len(S) // 2]
    S2 = S[len(S) // 2:]
    S2 = S2[::-1]
    for i in range(len(S) // 2):
        if S1[i] == '*' or S2[i] == '*':
            continue
        elif S1[i] == S2[i]:
            continue
        else:
            print('NO')
            break
    else:
        print('YES')
else:
    S1 = S[:len(S) // 2]
    S2 = S[len(S) // 2 + 1:]
    S2 = S2[::-1]
    for i in range(len(S) // 2):
        if S1[i] == '*' or S2[i] == '*':
            continue
        elif S1[i] == S2[i]:
            continue
        else:
            print('NO')
            break
    else:
        print('YES')