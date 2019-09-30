def main():
    n = int(input())
    aa = sorted(map(int, input().split()), reverse=True)
    score = sum(a for i, a in enumerate(aa) if i % 2 == 0)
    print(score)


if __name__ == "__main__":
    main()