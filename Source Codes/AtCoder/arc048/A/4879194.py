def main():
    a, b = map(int, input().split())
    if a < 0 and b > 0:
        print(b - a - 1)
    else:
        print(abs(b - a))


if __name__ == "__main__":
    main()