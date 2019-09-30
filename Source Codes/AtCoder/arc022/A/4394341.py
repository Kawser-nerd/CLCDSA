S = input()

res = 'NO'
tmp = 0
for i in range(len(S)):
    if (S[i] == 'I' or S[i] == 'i') and tmp == 0:
        tmp += 1
    if (S[i] == 'C' or S[i] == 'c') and tmp == 1:
        tmp += 1
    if (S[i] == 'T' or S[i] == 't') and tmp == 2:
        res = 'YES'
        
print(res)