#!/usr/bin/env python3

from sys import stdin, stdout, stderr

def solve_case(case):
    symbols = list(reversed("abcdefghijklmnopqrstuvwxyz"))
    H, W, altitudes = case
    labels = [[None] * W for i in range(H)]
    for i0 in range(H):
        for j0 in range(W):
            i, j = i0, j0
            path = []
            while True:
                if labels[i][j]:
                    symb = labels[i][j]
                    break
                path.append((i, j))
                neighbours = set()
                for di, dj in (-1, 0), (0, -1), (0, 1), (1, 0):
                    if 0 <= i + di < H and 0 <= j + dj < W and altitudes[i + di][j + dj] < altitudes[i][j]:
                        neighbours.add((i + di, j + dj))
                if not neighbours:
                    symb = symbols.pop()
                    break
                else:
                    i, j = min(neighbours, key=lambda p: (altitudes[p[0]][p[1]], p[0], p[1]))
            for i, j in path:
                labels[i][j] = symb
    return labels

def read_case():
    H, W = map(int, input().split())
    altitudes = [list(map(int, input().split())) for i in range(H)]
    return H, W, altitudes

def print_case(i, ans):
    print("Case #%d:" % i)
    for row in ans:
        print(" ".join(row))
    print("Case #%d:" % i, file=stderr)
    for row in ans:
        print(" ".join(row), file=stderr)

def main():
    for i in range(1, int(input()) + 1):
        print_case(i, solve_case(read_case()))

if __name__ == "__main__":
    main()

