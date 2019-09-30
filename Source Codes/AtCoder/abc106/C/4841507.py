S = input()
K = int(input())
for i in range(K):
    if not S[i] == '1':
        print(S[i])
        exit()
print('1')