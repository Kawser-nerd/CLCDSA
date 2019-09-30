def main():
    n = int(input())
    rr = input()
    pp = {"A": 4, "B": 3, "C": 2, "D": 1, "F": 0}
    p = 0
    for r in rr:
        p += pp[r]
    print(p / n)


if __name__ == "__main__":
    main()