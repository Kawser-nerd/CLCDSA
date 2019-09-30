def main():
    x, y = map(int, input().split())
    k = int(input())
    if k <= y:
        print(x + k)
    else:
        print(y + x - (k - y))


if __name__ == "__main__":
    main()