def main():
    n = int(input())
    ww = input().split()
    res = 0
    for i, w in enumerate(ww):
        if i == n - 1:
            w = w[:-1]
        if w == "TAKAHASHIKUN" or w == "Takahashikun" or w == "takahashikun":
            res += 1
    print(res)


if __name__ == "__main__":
    main()