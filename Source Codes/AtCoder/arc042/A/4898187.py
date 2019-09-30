def main():
    n, m = map(int, input().split())
    aa = [int(input()) for _ in range(m)]
    printeds = [False for _ in range(n)]
    for a in reversed(aa):
        if printeds[a - 1]:
            continue
        print(a)
        printeds[a - 1] = True
    for i in range(n):
        if not printeds[i]:
            print(i + 1)


if __name__ == "__main__":
    main()