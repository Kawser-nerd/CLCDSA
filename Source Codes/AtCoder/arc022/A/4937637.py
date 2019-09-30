S = input()
I = []
C = []
T = []
for j in range(len(S)):
    if S[j].lower() == 'i':
        I.append(j + 1)
    if S[j].lower() == 'c':
        C.append(j + 1)
    if S[j].lower() == 't':
        T.append(j + 1)
        
for c in C:
    if I == [] or T == []:
        print('NO')
        break
    elif I[0] < c < T[-1]:
        print('YES')
        break
else:
    print('NO')