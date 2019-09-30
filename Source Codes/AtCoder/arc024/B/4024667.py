N = int(input())
T = [int(input()) for _ in range(N)]

if sum(T) == N or sum(T) == 0:
    print(-1)
else:
    ans = 0
    mode = T[0]
    tmp = 1
    for i in list(range(1, N)) + list(range(N)):
        if T[i] == mode:
            tmp += 1
        else:
            mode = T[i]
            ans = max(ans, tmp)
            tmp = 1
    print(-(-ans//2))