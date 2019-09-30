import sys

S, K = [int(i) for i in input()], int(input())

if S[0] == 1:
    length = 1
    for i in range(1, len(S)):
        if S[i] == 1:
            length += 1
            pass
        else:
            idx = i
            break
else:
    print(S[0])
    sys.exit()

if len(S) == length:
    print(1)
else:
    if K-1 < idx:
        print(1)
    else:
        print(S[idx])