N = input()
S = 0
for i in range(len(N)):
    S += int(N[i])
if int(N) % S == 0:
    print('Yes')
else:
    print('No')