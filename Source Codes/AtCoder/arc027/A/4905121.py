def main():
    h, m = map(int, input().split())
    print(18 * 60 - (h * 60 + m))


if __name__ == "__main__":
    main()