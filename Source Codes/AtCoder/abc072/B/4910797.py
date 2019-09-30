S = list(input())

ss = []
for i in range(0,len(S)):
    if i % 2 == 0:
       ss.append(S[i])

print(''.join(ss))