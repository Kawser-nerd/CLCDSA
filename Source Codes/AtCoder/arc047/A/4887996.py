def main():
    n, l = map(int, input().split())
    s = input()
    t = 1
    res = 0
    for c in s:
        if c == "+":
            t += 1
            if t > l:
                t = 1
                res += 1
        else:
            t -= 1
    print(res)


if __name__ == "__main__":
    main()