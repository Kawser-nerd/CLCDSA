N = int(input())
h = list(map(int, input().split()))
f_h = [0 for i in range(N)]
judge = [False if f_h[i] != h[i] else True for i in range(N)]

ct = 0
while False in judge:
    flg = 0
    for i in range(N):
        if judge[i] is False:
            if i == N-1:
                f_h[i] += 1
                ct += 1
                if f_h[i] == h[i]:
                    judge[i] = True
            else:
                flg = 1
                f_h[i] += 1
                if f_h[i] == h[i]:
                    judge[i] = True
        else:
            if flg == 1:
                ct += 1
                flg = 0
            else:
                pass
print(ct)