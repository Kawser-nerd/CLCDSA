def main():
    n = int(input())
    mm = list(map(int, input().split()))
    res = 0
    for m in mm:
        if m < 80:
            res += 80 - m
    print(res)


if __name__ == "__main__":
    main()