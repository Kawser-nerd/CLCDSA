N, M = map(int, input().split(' '))

# ??????????
rem = M % 4

if rem == 0:
    if M // 4 <= N <= M // 2:
        print(M//2 - (M//2-N)*2, 0, M//2 - N)
    else:
        print('-1 -1 -1')
elif rem == 1:
    if M // 4 + 1 <= N <= M // 2:
        print(M//2 - (M//2-N)*2-1, 1, M//2 - N)
    else:
        print('-1 -1 -1')
elif rem == 2:
    if M // 4 + 1 <= N <= M // 2:
        print(M//2 - (M//2-N)*2, 0, M//2 - N)
    else:
        print('-1 -1 -1')
elif rem == 3:
    if M // 4 + 1 <= N <= M // 2:
        print(M//2 - (M//2-N)*2-1, 1, M//2 - N)
    else:
        print('-1 -1 -1')