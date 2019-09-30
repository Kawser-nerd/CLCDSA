N = input()

SN = 0
for n in N:
    SN += int(n)

if int(N)%SN == 0:
    print('Yes')
else:
    print('No')