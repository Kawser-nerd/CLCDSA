S = list(str(input()))
flag = 'A'
count = 0
for i in range(len(S)):
    if (S[i] == 'I' or S[i] == 'i') and count == 0:
        flag = 'I'
        count = 1
    if (S[i] == 'C' or S[i] == 'c') and flag == 'I':
        flag = 'C'
    if (S[i] == 'T' or S[i] == 't') and flag == 'C':
        flag = 'T'
if flag == 'T':
    print("YES")
else:
    print("NO")