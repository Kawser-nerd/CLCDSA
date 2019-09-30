def main():
    s = input()
    cs = []
    for c in s:
        if c in "0123456789":
            cs.append(c)
    print(int("".join(cs)))


if __name__ == "__main__":
    main()