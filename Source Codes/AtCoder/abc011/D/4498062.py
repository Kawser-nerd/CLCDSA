def combination(n, r):
    """
    :param n: the count of different items
    :param r: the number of select
    :return: combination
    n! / (r! * (n - r)!)
    """
    r = min(n - r, r)
    result = 1
    for i in range(n, n - r, -1):
        result *= i
    for i in range(1, r + 1):
        result //= i
    return result

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
        tmpx = combination(x, (x - cnt_x) // 2) / (2 ** N)
        tmpy = combination(y, (y - cnt_y) // 2) / (2 ** N)
        ans += tmpx * tmpy * combination(N, i)
    print(ans)