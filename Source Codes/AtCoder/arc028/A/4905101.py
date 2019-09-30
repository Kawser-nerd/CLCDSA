def main():
    n, a, b = map(int, input().split())
    while True:
        n -= a
        if n <= 0:
            print("Ant")
            return
        n -= b
        if n <= 0:
            print("Bug")
            return


if __name__ == "__main__":
    main()