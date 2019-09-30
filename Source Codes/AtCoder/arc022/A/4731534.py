s = input().upper()
I = s.find('I')
C = s[I:].find('C') + I
T = s[C:].find('T') + C
if I < C and C < T and - 1 not in [I, C, T]:
    print('YES')
else:
    print('NO')