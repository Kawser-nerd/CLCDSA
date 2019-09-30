N = input()
S = sum(list(map(int, N)))
if int(N) % S == 0:
    print('Yes')
else:
    print('No')