from scipy.misc import comb
N, D = map(int, input().split())
X, Y = map(int, input().split())
if X % D != 0 or Y % D != 0:
    print(0)
    exit()
else:
    ans = 0
    cnt_x = abs(X) // D
    cnt_y = abs(Y) // D

    for i in range(N + 1):
        x = i
        y = N - i
        if x < cnt_x or y < cnt_y:
            continue
        if (x - cnt_x) % 2 != 0 or (y - cnt_y) % 2 != 0:
            continue
        tmpx = comb(x, (x - cnt_x) // 2) / (2 ** N)
        tmpy = comb(y, (y - cnt_y) // 2) / (2 ** N)
        ans += tmpx * tmpy * comb(N, i)
    print(ans)