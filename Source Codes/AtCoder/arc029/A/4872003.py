from itertools import permutations


def main():
    n = int(input())
    ts = [int(input()) for _ in range(n)]
    res = 1 << 30
    for us in permutations(ts):
        for i in range(n):
            res = min(res, max(sum(us[:i]), sum(us[i:])))
    print(res)


if __name__ == "__main__":
    main()