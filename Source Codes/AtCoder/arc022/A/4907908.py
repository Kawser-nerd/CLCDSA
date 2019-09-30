def main():
    s = input()
    state = 0
    for c in s.lower():
        if c == "i" and state == 0:
            state = 1
        elif c == "c" and state == 1:
            state = 2
        elif c == "t" and state == 2:
            state = 3
    if state == 3:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()