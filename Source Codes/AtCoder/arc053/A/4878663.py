def main():
    h, w = map(int, input().split())
    print(2 * (h - 1) * (w - 1) + h - 1 + w - 1)


if __name__ == "__main__":
    main()