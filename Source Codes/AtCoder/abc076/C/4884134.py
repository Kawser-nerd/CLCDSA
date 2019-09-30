Sp = list(input())
T = list(input())

len_Sp = len(Sp)
len_T = len(T)
restorable = False
max_i = 0
if len_Sp >= len_T:
    for i in range(len_Sp - len_T, -1, -1):
        for j in range(len_T):
            if Sp[i + j] != '?' and Sp[i + j] != T[j]:
                break
        else:
            #Sp[i : i + len_T] = T
            max_i = max(max_i, i)
            restorable = True
if restorable:
    Sp[max_i : max_i + len_T] = T
    print(''.join(Sp).replace('?', 'a'))
else:
    print('UNRESTORABLE')
#print(''.join(Sp).replace('?', 'a') if restorable else 'UNRESTORABLE')