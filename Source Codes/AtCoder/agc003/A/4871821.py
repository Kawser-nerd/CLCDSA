S = input()
N = len(S)
d = [0,0,0,0]
s = ['N','W','S','E']
for i in range(N):
    for j in range(4):
        if S[i] == s[j]:
            d[j] += 1
            break

flag = True
if (d[0] == 0 and d[2] == 0) or (d[0] != 0 and d[2] != 0):
    pass
else:
    flag = False
if (d[1] == 0 and d[3] == 0) or (d[1] != 0 and d[3] != 0):
    pass
else:
    flag = False
    
if flag:
    print('Yes')
else:
    print('No')