def main():
    a, b = input().split()
    subs = [
        int(a) - int(b),
        int("9" + a[1] + a[2]) - int(b),
        int(a[0] + "9" + a[2]) - int(b),
        int(a[0] + a[1] + "9") - int(b),
        int(a) - int("1" + b[1] + b[2]),
        int(a) - int(b[0] + "0" + b[2]),
        int(a) - int(b[0] + b[1] + "0"),
    ]
    print(max(subs))


if __name__ == "__main__":
    main()