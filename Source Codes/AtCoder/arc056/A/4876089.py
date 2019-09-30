def main():
    a, b, k, l = map(int, input().split())
    res = min(a * k, b * ((k - 1) // l + 1), b * (k // l) + a * (k % l))
    print(res)


if __name__ == "__main__":
    main()