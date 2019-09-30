from itertools import combinations


def main():
    n, m = map(int, input().split())
    table = [[False for _ in range(n)] for _ in range(n)]
    for _ in range(m):
        x, y = map(int, input().split())
        table[x - 1][y - 1] = True
        table[y - 1][x - 1] = True
    res = 1
    for i in range(1, 1 << n):
        ps = [j for j in range(n) if (i >> j) & 1]
        if len(ps) <= 1:
            continue
        complete = True
        for (j, k) in combinations(ps, 2):
            if not table[j][k]:
                complete = False
                break
        if complete:
            res = max(res, len(ps))
    print(res)


if __name__ == "__main__":
    main()