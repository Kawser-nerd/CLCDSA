def ARC082D():
    N = int(input())
    p = list(map(int, input().split()))
    cnt = 0
    if p[N - 1] == N:
        #print(p[N - 1], N)
        p[-2], p[-1] = p[-1], p[-2]
        cnt += 1

    for i in range(N - 1):
        if p[i] == i + 1:
            p[i], p[i + 1] = p[i + 1], p[i]
            cnt += 1
    print(cnt)
ARC082D()