def main():
    s = input()
    a, b, c, d = map(int, input().split())
    l = [c for c in s]
    l.insert(d, '"')
    l.insert(c, '"')
    l.insert(b, '"')
    l.insert(a, '"')
    print("".join(l))


if __name__ == "__main__":
    main()