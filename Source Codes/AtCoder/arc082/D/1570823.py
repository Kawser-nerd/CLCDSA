def calc_ans(x):
    if x < 0:
        return 0
    elif x < X:
        return x
    else:
        return X


if __name__ == '__main__':
    # ?????
    X = int(input())

    # ????????
    K = int(input())
    # ????????
    r = list(map(int, input().split()))
    # ??????
    Q = int(input())

    # r ?????????
    j = 0
    sign = -1
    s = 0
    e = X
    y = 0
    sand_quantity = [r[0]]
    for i in range(1, K):
        sand_quantity.append(r[i] - r[i - 1])

    chasm_time = 0
    for i in range(Q):
        # t:?? a:??? A ?????????
        t, a = list(map(int, input().split()))
        while j < K and r[j] < t:
            y += sign * sand_quantity[j]
            # s??????
            if y < 0:
                s += -y
                if e < s:
                    s = e
                y = 0
            # e??????
            if X < y + e - s:
                tmp_diff = (y + e - s) - X
                e -= tmp_diff
                if e < s:
                    e = s
            if X < y:
                y = X

            chasm_time = r[j]
            j += 1
            sign *= -1

        tmp_time = t - chasm_time

        if a < s:
            ret = y
        elif a < e:
            ret = y + a - s
        else:
            ret = y + e - s

        ret += tmp_time * sign

        print(calc_ans(ret))
        # print("s:" + str(s) + " e:" + str(e) + " y:" + str(y) + " a:" + str(a) + " ret:" + str(ret))