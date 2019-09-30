def check(_a):
    for i in range(0, len(_a)):
        if N <= _a[i]:
            return True
    else:
        return False


if __name__ == '__main__':
    N = int(input())
    a = list(map(int, input().split()))

    divide_num = [0 for i in range(N)]
    ans = 0
    while check(a):
        sum_num = 0
        for i in range(0, N):
            tmp = a[i] // N
            divide_num[i] = tmp
            sum_num += tmp
            ans += tmp

        a = [(a[i] % N + sum_num - divide_num[i]) for i in range(0, N)]

    print(ans)