#!/usr/bin/env python3
import sys


def solve(H: int, W: int, a: "List[List[int]]"):
    ans = []
    for i in range(H):
        for j in range(W-1):
            if a[i][j] % 2 == 1:
                ans.append([i+1, j+1, i+1, j+1+1])  # ??
                a[i][j] -= 1
                a[i][j+1] += 1
    j = W-1
    for i in range(H-1):
        if a[i][j] % 2 == 1:
            ans.append([i+1, j+1, i+1+1, j+1])  # ??
            a[i][j] -= 1
            a[i+1][j] += 1
    print(len(ans))
    for a in ans:
        print(" ".join(map(str, a)))

    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    H = int(next(tokens))  # type: int
    W = int(next(tokens))  # type: int
    a = [[int(next(tokens)) for _ in range(W)]
         for _ in range(H)]  # type: "List[List[int]]"
    solve(H, W, a)


if __name__ == '__main__':
    main()