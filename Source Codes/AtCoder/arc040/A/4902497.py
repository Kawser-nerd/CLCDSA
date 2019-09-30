from collections import Counter


def main():
    n = int(input())
    r = 0
    b = 0
    for _ in range(n):
        counts = Counter(input())
        r += counts["R"]
        b += counts["B"]
    if r > b:
        print("TAKAHASHI")
    elif r < b:
        print("AOKI")
    else:
        print("DRAW")


if __name__ == "__main__":
    main()