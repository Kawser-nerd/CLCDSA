def main():
    n = int(input())
    print(min((n // 10) * 100 + (n % 10) * 15, ((n - 1) // 10 + 1) * 100))


if __name__ == "__main__":
    main()