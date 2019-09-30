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
    R, C, N = ILI()
    num_point = []
    for __ in range(N):
        x_1, y_1, x_2, y_2 = ILI()
        num_point.append([(x_1, y_1), (x_2, y_2)])
    return R, C, N, num_point


# ??? (0, 0) ???????????? 1 ?????????? point ???????
# ?????????????
def change_edge_point(R, C, point):
    x, y = point
    if x == 0:
        return R * 2 + C + (C - y)
    if x == R:
        return R + y
    if y == 0:
        return x
    if y == C:
        return R + C + (R - x)


def solve(R, C, N, num_point):
    point_double = []
    for ind, point in enumerate(num_point):
        p_1, p_2 = point
        if ((p_1[0] == 0 or p_1[0] == R) or (p_1[1] == 0 or p_1[1] == C)) and ((p_2[0] == 0 or p_2[0] == R) or (p_2[1] == 0 or p_2[1] == C)):
            point_double.append((ind + 1, change_edge_point(R, C, p_1)))
            point_double.append((ind + 1, change_edge_point(R, C, p_2)))
    point_double.sort(key=lambda  x: x[1])
    stack = []
    for point in point_double:
        if len(stack) == 0:
            stack.append(point[0])
            continue
        if point[0] == stack[-1]:
            stack.pop()
        else:
            stack.append(point[0])
    
    if len(stack) == 0:
        return "YES"
    else:
        return "NO"
    

def main():
    params = read()
    print(solve(*params))


if __name__ == "__main__":
    main()