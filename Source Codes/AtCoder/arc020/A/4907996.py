def main():
    a, b = map(int, input().split())
    a = abs(a)
    b = abs(b)
    if a < b:
        print("Ant")
    elif a > b:
        print("Bug")
    else:
        print("Draw")


if __name__ == "__main__":
    main()