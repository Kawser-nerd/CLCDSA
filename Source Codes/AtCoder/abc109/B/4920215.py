N = int(input())
W = [input() for i in range(N)]
flag = True

for i in range(N-1):
    if W[i][len(W[i])-1] != W[i+1][0]:
        flag = False
        
for i in range(N):
    for j in range(N):
        if i != j:
            if W[i] == W[j]:
                flag = False

if flag:
    print('Yes')
else:
    print('No')