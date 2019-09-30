def main():
    n, k = map(int, input().split())
    tt = [int(input()) for _ in range(n)]
    for i in range(2, n):
        if tt[i] + tt[i - 1] + tt[i - 2] < k:
            print(i + 1)
            return
    print(-1)


if __name__ == "__main__":
    main()