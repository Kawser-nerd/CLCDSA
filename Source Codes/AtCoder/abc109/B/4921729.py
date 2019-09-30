N = int(input())
W = [input() for i in range(N)]

f = True
for i in range(len(W)-1):
    if W[i][-1] != W[i+1][0]:
        f = False
        break

if f and N==len(set(W)):
    print('Yes')
else:
    print('No')