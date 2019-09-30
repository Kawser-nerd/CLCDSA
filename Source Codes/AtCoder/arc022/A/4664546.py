S = input()
lS = len(S)
index = 0
s_i = 0
s1 = 'ict'
s2 = 'ICT'
while index < lS:
    if S[index] == s1[s_i] or S[index] == s2[s_i]:
        s_i += 1
        if s_i == 3:
            print('YES')
            break
    index += 1
else:
    print('NO')