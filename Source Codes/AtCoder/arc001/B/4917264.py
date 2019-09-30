def main():
    n = int(input())
    counts = [0] * 4
    for c in input():
        counts[int(c) - 1] += 1
    print(max(counts), min(counts))


if __name__ == "__main__":
    main()