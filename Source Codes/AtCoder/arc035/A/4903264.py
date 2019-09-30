def main():
    s = input()
    l = len(s)
    for i in range(l // 2):
        if s[i] != "*" and s[l - 1 - i] != "*" and s[i] != s[l - 1 - i]:
            print("NO")
            return
    print("YES")


if __name__ == "__main__":
    main()