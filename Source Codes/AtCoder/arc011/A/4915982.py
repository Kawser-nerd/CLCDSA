def main():
    m, n, N = map(int, input().split())
    res = 0
    while N >= m:
        a, b = divmod(N, m)
        N = a * n + b
        res += a * m
    res += N
    print(res)


if __name__ == "__main__":
    main()