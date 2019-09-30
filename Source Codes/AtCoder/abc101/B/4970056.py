N = input()

SN = 0
for i in N:
    SN += int(i)

if int(N) % SN == 0:
    print('Yes')
else:
    print('No')