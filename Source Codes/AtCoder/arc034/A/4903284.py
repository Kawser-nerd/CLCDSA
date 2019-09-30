def main():
    n = int(input())
    res = 0
    for _ in range(n):
        aa = list(map(int, input().split()))
        res = max(res, sum(aa[:-1]) + aa[-1] * 11 / 90)
    print(res)


if __name__ == "__main__":
    main()