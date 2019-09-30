N = int(input())

for i in range(0,26):
    for j in range(0,18):
        if 4*i+7*j == N:
            print('Yes')
            exit()

print('No')