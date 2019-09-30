def main():
    p = 2000000000000
    a, k = map(int, input().split())
    if k == 0:
        print(p - a)
        return
    d = 0
    while a < p:
        a += 1 + k * a
        d += 1
    print(d)


if __name__ == "__main__":
    main()