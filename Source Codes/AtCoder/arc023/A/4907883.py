def f(y, m, d):
    if m <= 2:
        y -= 1
        m += 12
    return 365 * y + y // 4 - y // 100 + y // 400 + 306 * (m + 1) // 10 + d - 429


def main():
    y = int(input())
    m = int(input())
    d = int(input())
    print(f(2014, 5, 17) - f(y, m, d))


if __name__ == "__main__":
    main()