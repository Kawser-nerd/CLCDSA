from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = 10 ** 10

def check(ans1, ans2, field):
    h, w = len(ans1), len(ans1[0])
    ans = [[0] * w for _ in range(h)]
    for y in range(h):
        for x in range(w):
            c = "#" if ans1[y][x] == ans2[y][x] == "#" else "."
            if field[y][x] != c:
                print(y, x)


def main():
    H, W = map(int, input().split())
    field = []
    for _ in range(H):
        field.append(input())

    ans1, ans2 = [["."] * W for _ in range(H)], [["."] * W for _ in range(H)]
    for i in range(H):
        ans1[i][0] = "#"
        ans2[i][-1] = "#"
        if i % 2 == 0:
            ans1[i] = ["#"] * (W - 1) + ["."]
        else:
            ans2[i] = ["."] + ["#"] * (W - 1)

    for y in range(H):
        for x in range(W):
            if field[y][x] == "#":
                if y % 2 == 0:
                    ans2[y][x] = "#"
                else:
                    ans1[y][x] = "#"
    
    for line in ans1:
        print("".join(line))
    print()
    for line in ans2:
        print("".join(line))


if __name__ == '__main__':
    main()