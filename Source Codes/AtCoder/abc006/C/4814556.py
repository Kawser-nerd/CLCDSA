N, M = map(int, input().split(' '))

if M % 4 == 0:
    ans = (M//2-(M//2-N)*2, 0, M//2-N) if M//4 <= N <= M//2 else (-1, -1, -1)
elif M % 4 == 2:
    ans = (M//2-(M//2-N)*2, 0, M//2-N) if M//4+1 <= N <= M//2 else (-1, -1, -1)
else:
    ans = (M//2-(M//2-N)*2-1, 1, M//2-N) if M//4+1 <= N <= M//2 else (-1, -1, -1)
print(ans[0], ans[1], ans[2])