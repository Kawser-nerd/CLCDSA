S = input()
T = input()

l = ['a', 't', 'c', 'o', 'd', 'e', 'r']

Flag = 0
for i in range(len(S)):
    if S[i] == '@':
        if T[i] != '@' and T[i] not in l:
            Flag = 1
            break
    elif T[i] == '@':
        if S[i] not in l:
            Flag = 1
            break
    elif S[i] != T[i]:
        Flag = 1
        break
        
if Flag == 0:
    print('You can win')
else:
    print('You will lose')