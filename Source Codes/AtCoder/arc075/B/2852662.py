def main():
    n, a, b = map(int, input().split())
    ms = [int(input()) for i in range(n)]

    ms.sort()

    times = [0 for i in range(n)]
    for i in range(n):
        times[i] = (ms[i]+b-1) // b

    left, right = -1, max(times)
    while right - left > 1:
        mid = (left+right) // 2
        center = 0
        for i in range(n):
            if ms[i] - mid * b > 0:
                exd = a - b
                center += (ms[i]-mid*b+exd-1) // exd

        if center - mid > 0:
            left = mid
        else:
            right = mid

    print(right)


if __name__ == '__main__':
    main()