S = input()
T = input()
dic1 = {}
dic2 = {}
flag = True
for i , j in zip(S, T):
    if i in dic1:
        if dic1[i] != j:
            flag = False
            break
    dic1[i] = j
    if j in dic2:
        if dic2[j] != i:
            flag = False
            break
    dic2[j] = i
if flag:
    print('Yes')
else:
    print('No')