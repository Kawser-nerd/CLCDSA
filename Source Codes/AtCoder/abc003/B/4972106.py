S = list(input())
T = list(input())
pit = 0
N = len(S)


for i in range(N):
    if S[i] != T[i]:
        if S[i] == '@' :
            if T[i] == 'a' or T[i]=='t' or T[i]=='c' or T[i]=='o' or T[i]=='d' or T[i]=='e' or T[i]=='r' or T[i]=='@':
                pit = pit +1
            else:
                print('You will lose')
                break
        elif T[i] == '@':
            if S[i] == 'a' or S[i]=='t' or S[i]=='c' or S[i]=='o' or S[i]=='d' or S[i]=='e' or S[i]=='r' or S[i]=='@':
                pit = pit +1
            else:
                print('You will lose')
                break
        else:
            print('You will lose')
            break
    else:
        pit = pit +1

if pit == N:
    print('You can win')