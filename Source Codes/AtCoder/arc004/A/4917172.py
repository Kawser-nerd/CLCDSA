from math import sqrt


def main():
    n = int(input())
    pp = [list(map(int, input().split())) for _ in range(n)]
    res = 0
    for i in range(n):
        for j in range(1, n):
            if i == j:
                continue
            res = max(res, (pp[i][0] - pp[j][0]) ** 2 + (pp[i][1] - pp[j][1]) ** 2)
    print(sqrt(res))


if __name__ == "__main__":
    main()