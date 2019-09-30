def main():
    A, B = list(map(int, input().rstrip().split()))
    d = abs(B - A)

    cnt = d // 10
    d = d - (d // 10) * 10

    if d >= 5:
        cnt += 1 + min(d - 5, 10 - d)
    elif d > 0:
        cnt += min(1 + (5 - d), d)
    else:
        pass

    print("{}".format(cnt))


if __name__ == '__main__':
    main()