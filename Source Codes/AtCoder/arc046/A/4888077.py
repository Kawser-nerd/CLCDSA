def same(i):
    return len(set(c for c in str(i))) == 1


def main():
    n = int(input())
    i = 0
    while n > 0:
        i += 1
        if same(i):
            n -= 1
    print(i)


if __name__ == "__main__":
    main()