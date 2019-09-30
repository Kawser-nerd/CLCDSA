def main():
    n, a, b = map(int, input().split())
    if n <= 5:
        print(n * b)
    else:
        print(5 * b + (n - 5) * a)


if __name__ == "__main__":
    main()