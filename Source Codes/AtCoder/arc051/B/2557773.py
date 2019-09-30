K = int(input())


def rec(a, b, cnt):
    if K == cnt:
        print(a, b)
        exit()
    else:
        cnt += 1
        rec(a+b, a, cnt)


rec(1, 1, 0)