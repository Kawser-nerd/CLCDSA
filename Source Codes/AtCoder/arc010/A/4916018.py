def main():
    n, m, a, b = map(int, input().split())
    cc = [int(input()) for _ in range(m)]
    for i, c in enumerate(cc):
        if n <= a:
            n += b
        if n < c:
            print(i + 1)
            return
        n -= c
    print("complete")


if __name__ == "__main__":
    main()