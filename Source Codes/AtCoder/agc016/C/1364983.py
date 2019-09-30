# coding: utf-8
import array, bisect, collections, copy, heapq, itertools, math, random, re, string, sys, time
sys.setrecursionlimit(10 ** 7)
INF = 10 ** 20
MOD = 10 ** 9 + 7


def II(): return int(input())
def ILI(): return list(map(int, input().split()))
def IAI(LINE): return [ILI() for __ in range(LINE)]
def IDI(): return {key: value for key, value in ILI()}


def read():
    H, W, h, w = ILI()
    return H, W, h, w


def solve(H, W, h, w):
    if H % h == 0 and W % w == 0:
        return False, None
    else:
        matrix = [[10 ** 3] * W for __ in range(H)]
        val = - (h * w * 1000) + 999
        for _h in range(h - 1, H, h):
            for _w in range(w - 1, W, w):
                matrix[_h][_w] = val

    return True, matrix


def main():
    params = read()
    ans_bool, matrix = solve(*params)
    if ans_bool:
        print("Yes")
        for row in matrix:
            print(" ".join(map(str, row)))
    else:
        print("No")


if __name__ == "__main__":
    main()